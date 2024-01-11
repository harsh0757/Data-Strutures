#include<bits/stdc++.h>
using namespace std;

//functional
int add1(int n){
    if(n==0){
        return 0;
    }
    return n+add1(n-1);
}

//parameterised
void add(int i, int sum) {
    if(i<1){
        cout<<sum<<endl;
        return;
    }
    add(i-1, sum+i);
}

int main(){
    int n;
    cin>>n;
    // add(n,0);
    cout<<add1(n)<<endl;
}