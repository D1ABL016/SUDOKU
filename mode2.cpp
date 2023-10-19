#include"mode2.h"
#include<unordered_map>
using namespace std;

bool issolvable(vector<vector<int>> &grid){
    unordered_map <char,bool> rows;
    unordered_map <char,bool> cols;
    unordered_map <char,bool> cell;

    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){

            char ch =grid[i][j];
            char ch2 = grid[j][i];

            if (cols[ch2]&& ch2!=0)
            return false;
            else
            cols[ch2] = true;

            if(rows[ch] && ch!=0)
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

           
           if(cell[ch] && ch!=0)
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

bool isValid(int row,int col,vector<vector<int>> &grid,int val){
   for (int i=0;i<9;i++){
    if (grid[row][i]==val || (grid[i][col]==val))
    return false;
    if (grid[3*(row/3)+i/3][3*(col/3)+i%3]==val)
    return false;
   }
   return true;
}

bool SudokuSolver(vector<vector<int>> &grid){
    for (int row =0;row<9;row++){
        for (int col =0;col<9;col++){
            if (grid[row][col]==0){
                for (int val =1;val<=9;val++){
                    
                    if (isValid(row,col,grid,val)){
                        grid[row][col]=val;
                        bool possible =  SudokuSolver(grid);
                        if (possible)
                        return true;
                        else
                        grid[row][col]=0;
                    }
                }
                return false;
            }

        }
    }
    return true;
}

void print(vector<vector<int>> &g){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}

void inputGrid(vector<vector<int>> &grid){
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         cin>>grid[i][j];
    //         if (cin.fail()) {
    //         throw runtime_error("program terminated as you entered wrong input");
    //         }
    //     }        
    // }
    // bool solvable = issolvable(grid);
    // while(!solvable){
    //     cout<<"enter a valid sudoku grid :  "<<endl;
    //     for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         cin>>grid[i][j];
    //     }        
    // }
    //     solvable = issolvable(grid);
    // }
    int attemptsRemaining=5;
    while(attemptsRemaining>=0){
        try{
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    string input;
                    cin>>input;
                    int element = stoi(input);
                    if (element>9 || element<0)
                    throw invalid_argument("");
                    grid[i][j]=element;
                }                
            }
            break;
        }
        
        catch(invalid_argument& e){
            cout<<"enter a valid number from 1 to 9"<<endl;
        }
        catch(...){
            cout<<"an unexpecteed error occured"<<endl;
        }
        // print(grid);
        attemptsRemaining--;
        if (attemptsRemaining>0)
        cout<<"attempts remaining : "<<attemptsRemaining<<endl;
    }
    // isso
    
}


