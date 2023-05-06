#include <iostream>
using namespace std;

int sum(int a,int b){
    return a+b;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<"Sum of numbers : "<<sum(a,b)<<endl;
}