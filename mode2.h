#ifndef MODE2_H
#define MODE2_H
#include <vector>
#include<iostream>
#include<unordered_map>
using namespace std;
 
bool issolvable(vector<vector<int>> &grid);
void inputGrid(vector<vector<int>> &grid);
bool SudokuSolver(vector<vector<int>> &grid);
bool isValid(int row,int col,vector<vector<int>> &grid,int val);


#endif