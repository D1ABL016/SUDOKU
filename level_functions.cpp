#include"level_functions.h"
#include"RandomNumberGenerator.cpp"
using namespace std;

void generateGrid(vector<vector<char>> &grid,int numberOfDigitsGenerated){
    while(numberOfDigitsGenerated){
        int row = RandomGenerator(0,8);
        int col = RandomGenerator(0,8);
        char num = char(RandomGenerator(48,57));
        cout<<row<<" "<<col<<" "<<num<<endl;
        grid[row][col] = num;
        numberOfDigitsGenerated--;
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


