#include"RandomNumberGenerator.h"

int RandomGenerator(int lower,int upper){
    srand(time(0)); 
  
    for(int i=0;i<2;i++){
        cout<<(rand()%(upper-lower+1))+lower<<" ";
    }
    cout<<endl;
    return 100;
}