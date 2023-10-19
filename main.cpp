#include "mode2.cpp"
// #include "mode2.h"
#include "level_functions.cpp"
// #include "level_functions.h"
using namespace std;


int main(){
    /*
    solvable
1 0 0 4 8 9 0 0 6
7 3 0 0 0 0 0 4 0
0 0 0 0 0 1 2 9 5
0 0 7 1 2 0 6 0 0
5 0 0 7 0 3 0 0 8
0 0 6 0 9 5 7 0 0
9 1 4 6 0 0 0 0 0
0 2 0 0 0 0 0 3 7
8 0 0 5 1 2 0 0 4
*/

/*
not solvable
0 0 3 0 4 0 0 0 0
0 0 8 0 0 3 8 3 0
0 9 8 7 0 0 0 0 3
1 0 3 6 0 0 0 0 7
3 0 0 0 2 0 0 0 8
0 7 6 0 0 0 8 6 0
0 2 4 0 0 0 3 5 1
4 4 6 0 0 0 3 2 8
0 4 9 0 0 0 8 2 0
*/
    try{
    bool mode = ModeChooser();/*fulla and final made this function(ModeChhooser ) on 19 oct 2:04 i have handled all the exceptions that i could think of*/
    vector<vector<int>> grid(9,vector<int>(9,0)) ;
    if (mode){
        
        pair<int,int>p = level_chooser();
        // int level = p.first;
        // int numberOfDigitsGenerated = p.second;
        // cout<<numberOfDigitsGenerated<<endl;
        // generateGrid(grid,numberOfDigitsGenerated);
        // bool solvable = isSolvable(grid); 
        // if (!solvable){
        //     // unsolvableTosolvable(grid);
        // }
        
    }
    else{/*fulla and final made this function(ModeChhooser ) on 19 oct 2:04 i have handled all the exceptions that i could think of*/
        cout<<"enter the sudoku table  :"<<endl;
        
            inputGrid(grid);        
            bool solved = SudokuSolver(grid);
            if (solved){
                cout<<endl<<"your answer is : "<<endl;
                GridPrinter(grid);
            }
            else{
                cout<<"the grid you entered is not solvable according to traditional sudoku rules"<<endl;
            }
     }
    }
    catch(...){
        cout<<"program terminated "<<endl;
    }
    cout<<"thank you  for using my program "<<endl;
    
    return 0; 
}