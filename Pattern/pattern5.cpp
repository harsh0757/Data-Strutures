// 1 2 3 
// 4 5 6 
// 7 8 9 

#include<iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int value = 1;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<value<<" ";
            value++;
        }
        cout<<endl;
    }
}