#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {2,3,5,6,7};
    vector<pair<int, int>> v_p = {{1,2}, {2,4}};
//range based loops
//we can take reference values also
    for(int it : v){ //it will get the copy of the values
        cout<<it<<" ";
    }
    cout<<endl;
//on vector pairs
    // for(pair<int,int> it : v_p){
    for(auto it : v_p){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
//auto keyword
    auto a = 1;
    cout<<a<<endl;

    for(auto it : v){  // we can use like this also
        cout<<it<<" ";
    }
}