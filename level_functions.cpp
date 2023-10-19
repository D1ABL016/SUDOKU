#include"level_functions.h"
#include<cmath>
#include<map>
#include<unordered_map>
#include"RandomNumberGenerator.cpp"
using namespace std;

bool ModeChooser(){  
    // it wil give the user 2 choice s  
    // first , does he want to play sudoku ?? 
    // second , does he wants to solve sudoku using ai?? 
    // 
    int choice;
    int count=0;
    while(count<=5){
    cout<<"enter choice "<<endl<<"1) do you want to play Sudoku ?? "<<endl<<"2) do you want to solve your sudoku using ai ?? "<<endl;
    try{
        string input;
        cin>>input;
        choice = stoi(input);
        if (choice!= 1 && choice !=2)
            //throw a custom error that will have the below body and will throw error when number is not 1 or 2
            throw 10;        
        else if (choice ==1)
            return true;        
        else 
            return false;        
    }
    catch (invalid_argument& e){
        cout<<"please enter a valid type of arguments  i.e 1 or 2"<<endl;
    }
    catch(int n){
        cout<<"enter either 1 or 2 "<<endl;

    }
    catch(...){
        cout<<"an unexpected error occured"<<endl;
    }
    if (count!=5)
        cout<<"Remaininng attempts "<<(5 - count)<<endl;
    count++;
    }
    if  (count==6)
    //throw an error that wil be in main program and will always terminate program
    throw runtime_error("program should be terminatefd");
return false;

}


bool isValid2(int row,int col,vector<vector<int>> &grid,char val){
   for (int i=0;i<9;i++){
    if (grid[row][i]==val || (grid[i][col]==val))
    return false;
    if (grid[3*(row/3)+i/3][3*(col/3)+i%3]==val)
    return false;
   }
   return true;
}

void unsolvableTosolvable(vector<vector<int>> &grid){
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

void generateGrid(vector<vector<int>> &grid,int numberOfDigitsGenerated){
    
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

void GridPrinter(vector<vector<int>> &grid){
    for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
}


pair<int,int> level_chooser(){// will give user the choice to play which ever level he wants to and
// also check for validation in it that is is he putting right choice ???
// it will also generate a grid accodinng to the level choosen
int level;
pair<int,int>p;
int RemainingAttemppts  = 5;
while(RemainingAttemppts>0){
    cout<<"Enter a level : "<<endl<<"1. easy "<<endl<<"2. medium"<<endl<<"3. hard"<<endl<<"4. expert"<<endl;
    try{
        string input;
        cin>>input;
        int temp = stoi(input);
        if (temp<=0 || temp>4)
        throw invalid_argument("");
        level = temp;
    }
    catch(invalid_argument& e){
        cout<<"enter  a valid number between 1 and 4 "<<endl;
    }
    catch(...){
        cout<<"an unexpected error occured "<<endl;
    }
    if (RemainingAttemppts>0)
        cout<<"attempts remaining : "<<RemainingAttemppts<<endl;
    RemainingAttemppts--;
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

bool isSolvable(vector<vector<int>> &grid){
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
