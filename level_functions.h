#ifndef LEVEL_FUNCTIONS_H
#define LEVEL_FUNCTIONS_H
#include <vector>
#include<iostream>
using namespace std;
void generateGrid(vector<vector<char>> &grid,int numberOfDigitsGenerated);
void GridPrinter(vector<vector<char>> &grid);
pair<int,int> level_chooser();
bool ModeChooser();
#endif
