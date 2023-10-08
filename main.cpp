#include"level_functions.cpp"
using namespace std;


int main(){
    
    bool mode = ModeChooser();
    if (mode){
        
        pair<int,int>p = level_chooser();
        int level = p.first;
        int numberOfDigitsGenerated = p.second;
        cout<<numberOfDigitsGenerated<<endl;
        vector<vector<char>> grid(9,vector<char>(9,'.')) ;
        generateGrid(grid,numberOfDigitsGenerated);
        
        
    }
    else{

    }
    
    return 0; 
}