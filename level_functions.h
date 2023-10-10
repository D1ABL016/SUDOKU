#ifndef LEVEL_FUNCTIONS_H
#define LEVEL_FUNCTIONS_H
#include <vector>
#include<iostream>
using namespace std;



void generateGrid(vector<vector<char>> &grid,int numberOfDigitsGenerated);
void GridPrinter(vector<vector<char>> &grid);
bool ModeChooser();
void unsolvableTosolvable(vector<vector<char>> &grid);
bool isValid2(int row,int col,vector<vector<char>> &grid,char val);
pair<int,int> level_chooser();
bool isSolvable(vector<vector<char>> &grid);


#endif
