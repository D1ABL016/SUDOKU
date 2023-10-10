#ifndef MODE2_H
#define MODE2_H
#include <vector>
#include<iostream>
#include<unordered_map>
using namespace std;
 
bool issolvable(vector<vector<char>> &grid);
void inputGrid(vector<vector<char>> &grid);
bool SudokuSolver(vector<vector<char>> &grid);
bool isValid(int row,int col,vector<vector<char>> &grid,char val);


#endif