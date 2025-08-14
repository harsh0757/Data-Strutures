#include<iostream>
using namespace std;

int fibonnaci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fibonnaci(n-1) + fibonnaci(n-2);
}

int main(){
    // cout << fibonnaci(5)<<endl;
    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cout << fibonnaci(i) << " "; //to print series;
    }
    cout << endl;
}