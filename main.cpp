#include "mode2.cpp"
// #include "mode2.h"
#include "level_functions.cpp"
// #include "level_functions.h"
using namespace std;


int main(){
    /*
1 . . 4 8 9 . . 6 
7 3 . . . . . 4 .
. . . . . 1 2 9 5
. . 7 1 2 . 6 . .
5 . . 7 . 3 . . 8
. . 6 . 9 5 7 . .
9 1 4 6 . . . . .
. 2 . . . . . 3 7
8 . . 5 1 2 . . 4
*/

/*
. . 3 . 4 . . . . 
. . 8 . . 3 8 3 . 
. 9 8 7 . . . . 3 
1 . 3 6 . . . . 7 
3 . . . 2 . . . 8 
. 7 6 . . . 8 6 . 
. 2 4 . . . 3 5 1 
4 4 6 . . . 3 2 8 
. 4 9 . . . 8 2 .
*/
    bool mode = ModeChooser();
    vector<vector<char>> grid(9,vector<char>(9,'.')) ;
    if (mode){
        
        pair<int,int>p = level_chooser();
        int level = p.first;
        int numberOfDigitsGenerated = p.second;
        cout<<numberOfDigitsGenerated<<endl;
        generateGrid(grid,numberOfDigitsGenerated);
        bool solvable = isSolvable(grid); 
        if (!solvable){
            // unsolvableTosolvable(grid);
        }
        
    }
    else{
        cout<<"enter the sudoku table  :"<<endl;
        inputGrid(grid);        
        SudokuSolver(grid);
        cout<<endl<<"your answer is : "<<endl;
        GridPrinter(grid);
    }
    
    return 0; 
}