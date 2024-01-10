#include<bits/stdc++.h>
using namespace std;

void print(int i, int n){
    if(i<1){
        return;
    }
    // print(i-1,n);//backtracking
    cout<<i<<endl;
    print(i-1,n);//recursion
}

int main(){
    int n;
    cout<<"Enter the number : "<<endl;
    cin>>n;
    print(n,n);
}