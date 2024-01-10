#include<bits/stdc++.h>
using namespace std;

void print(int i, int n){
    if(i>n){
        return;
    }
    // print(i+1,n);//backtracking
    cout<<i<<endl;
    // print(i+1,n);//recursion
}

int main(){
    int n;
    cin>>n;
    print(1,n);
}