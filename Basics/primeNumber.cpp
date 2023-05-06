#include <iostream>
using namespace std;

int prime1(int n){
    for(int i=2;i<n/2;i++){
        if(i%n != 0){
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

int main(){
    int N;
    cin>>N;
    // prime(N);
    if(prime1(N)){
        cout<<"Prime Number"<<endl;
    } else {
        cout<<"Not a prime number"<<endl;
    }
}