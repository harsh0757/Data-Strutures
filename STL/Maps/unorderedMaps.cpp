#include<iostream>
#include <unordered_map>
using namespace std;

void print(unordered_map<int, string> &m){
    cout<<m.size()<<endl;
    for(auto &it : m){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
}

int main(){
//difference
//1.inbuilt implementation --> uses hash tables
//2.Time complexity --> o(1) insertion and accessing
//3.Valid key data types

//declartion
    unordered_map<int, string> mpp;

    mpp[1] = "abc";  //O(1)
    mpp[5] = "cdc";
    mpp[3] = "acd";
    mpp[5] = "def";
    mpp[6];
//prints in random order
    print(mpp);

    auto it = mpp.find(7);
    if(it != mpp.end()) mpp.erase(it);
}