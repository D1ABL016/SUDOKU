#include"RandomNumberGenerator.h"

vector<int> R2(int n, int lower,int upper){
    srand(time(0));
    vector<int>ans;
    for (int i = 0; i < n; i++)
    {
        int num = (rand()%(upper-lower+1))+lower;
        
        // cout<<num<<endl;
        ans.push_back(num);
    }
    
    return ans;
}

set<pair<int,int>> RandomGenerator(int n, int lower,int upper){
    srand(time(0)); 
  
    set<pair<int,int>> s;   
    while(s.size()!=n){
        int num1 = (rand()%(upper-lower+1))+lower;
        int num2 = (rand()%(upper-lower+1))+lower;
        // cout<<num1<<" "<<num2<<endl;
        s.insert({num1,num2});
        
    }
    return s;
}