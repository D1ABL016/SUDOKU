#ifndef LEVEL_FUNCTIONS_H
#define LEVEL_FUNCTIONS_H
#include <vector>
#include<iostream>
using namespace std;



void generateGrid(vector<vector<int>> &grid,int numberOfDigitsGenerated);
void GridPrinter(vector<vector<int>> &grid);
bool ModeChooser();
void unsolvableTosolvable(vector<vector<int>> &grid);
bool isValid2(int row,int col,vector<vector<int>> &grid,char val);
pair<int,int> level_chooser();
bool isSolvable(vector<vector<int>> &grid);


#endif
