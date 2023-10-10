#include"level_functions.h"
#include<cmath>
#include<map>
#include<unordered_map>
#include"RandomNumberGenerator.cpp"
using namespace std;

bool isValid2(int row,int col,vector<vector<char>> &grid,char val){
   for (int i=0;i<9;i++){
    if (grid[row][i]==val || (grid[i][col]==val))
    return false;
    if (grid[3*(row/3)+i/3][3*(col/3)+i%3]==val)
    return false;
   }
   return true;
}

void unsolvableTosolvable(vector<vector<char>> &grid){
    for(int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            if (grid[i][j] != '.'){
                bool validity = isValid2(i,j,grid,grid[i][j]);
                if(!validity){
                    while (!validity){
                        int val = grid[i][j];
                        grid[i][j] = val++; 
                        validity = isValid2(i,j,grid,grid[i][j]);
                    }
                    
                }
            }
        }
    }
}

void generateGrid(vector<vector<char>> &grid,int numberOfDigitsGenerated){
    
    // vector<int>rows =R2(numberOfDigitsGenerated*2,0,8);
    // vector<int>cols =R2(numberOfDigitsGenerated,0,8);
    set<pair<int,int>> mpp = RandomGenerator(numberOfDigitsGenerated,0,8);
    vector<int>value = R2(numberOfDigitsGenerated,49,57);
    int j=0; 
    for (auto x:mpp){
        int r = x.first;
        int c = x.second;
        char v = char(value[j]);
        j++;
        grid[r][c] = v;
    }           
    GridPrinter(grid);
}

void GridPrinter(vector<vector<char>> &grid){
    for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
}

bool ModeChooser(){
    // it wil give the user 2 choice s 
    // firts , does he want to play sudoku ?? 
    // second , does he wants tos olve sudoky using ai??
    int choice;
    cout<<"enter choice "<<endl<<"1) do you want to play Sudoku ?? "<<endl<<"2) do you want to solve your sudoku using ai ?? "<<endl;
    cin>>choice;
    while(choice ==0 || choice >2){
        cout<<"enter a valid choice "<<endl<<"1) do you want to play Sudoku ?? "<<endl<<"2) do you want to solve your sudoku using ai ?? "<<endl;
        cin>>choice;
    }
    if (choice==1)
    return true;
    else
    return false;


}

pair<int,int> level_chooser(){// will give user the choice to play which ever level he wants to and
// also check for validation in it that is is he putting right choice ???
// it will also generate a grid accodinng to the level choosen
int level;
pair<int,int>p;
cout<<"Enter a level : "<<endl<<"1. easy "<<endl<<"2. medium"<<endl<<"3. hard"<<endl<<"4. expert"<<endl;
cin>>level;
while(level==0 || level > 4){
    cout<<"Enter a valid level : "<<endl<<"1. easy "<<endl<<"2. medium"<<endl<<"3. hard"<<endl<<"4. expert"<<endl;
    cin>>level;
}
p.first=level;
int numberOfDigitsGenerated;
switch(level){
    case 1:
        numberOfDigitsGenerated = 36;
        // generateGrid(grid,numberOfDigitsGenerated);
        break;
    case 2:
        numberOfDigitsGenerated = 30;
        // generateGrid(grid,numberOfDigitsGenerated);
        break;
    case 3:
        numberOfDigitsGenerated = 28;
        // generateGrid(grid,numberOfDigitsGenerated);
        break;
    case 4:
        numberOfDigitsGenerated = 23;
        // generateGrid(grid,numberOfDigitsGenerated);
        break;
}
p.second=numberOfDigitsGenerated;
return p;
}

bool isSolvable(vector<vector<char>> &grid){
    unordered_map <char,bool> rows;
    unordered_map <char,bool> cols;
    unordered_map <char,bool> cell;

    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){

            char ch =grid[i][j];
            char ch2 = grid[j][i];

            if (cols[ch2]&& ch2!='.')
            return false;
            else
            cols[ch2] = true;

            if(rows[ch] && ch!='.')
                return false;            
            else
                rows[ch] = true;                
        }
        rows.clear();
        cols.clear();
    }
    // bool rc = true;

    //checking for cells 
    for (int r = 0; r < 9; r++){
       for (int c = 0; c < 9; c++){
        for (int i = 0; i < 9; i++){
           int a = (3*(r/3))+i/3;
           int b = (3*(c/3))+i%3;
           char ch = grid[a][b];
           if(cell[ch]&& ch!='.')
           return false;
           else
           cell[ch] =true;
        }
        cell.clear();
        c+=2;         
       }  
       r+=2;     
    }
    // bool ce = true;
    return true;
}
