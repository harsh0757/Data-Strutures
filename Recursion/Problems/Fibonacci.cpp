#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n;
    cout<<"Enter a numner to print Fibonacci series : "<<endl;
    cin>>n;
    cout<<fibonacci(n)<<endl;
}