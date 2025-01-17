/*
Given N strings, print unique strings in lexographical order with their frequency
N<=10^5
|S| <= 100
*/
#include<iostream>
#include<map>
using namespace std;

void print(map<string, int> &m){
    cout<<m.size()<<endl;
    for(auto &it : m){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
}

int main(){
    map<string, int> mpp;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mpp[s] = mpp[s] + 1;
    }
    print(mpp);
}