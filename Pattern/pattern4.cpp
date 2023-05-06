// 5 4 3 2 1 
// 5 4 3 2 1 
// 5 4 3 2 1 
// 5 4 3 2 1 
// 5 4 3 2 1 

#include<iostream>

using namespace std;

int main(){
    int N;
    cin>>N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<N-j+1<<" ";
        }
        cout<<endl;
    }
}