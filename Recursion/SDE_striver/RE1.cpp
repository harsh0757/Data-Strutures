#include<iostream>
using namespace std;

void print(int n, int i){
    if(i>n) return;
    cout<<i<<endl;
    print(n, i+1);
}

int main(){
    print(5,1);
}