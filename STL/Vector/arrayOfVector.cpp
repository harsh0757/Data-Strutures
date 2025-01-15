#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    cout<<"Size : "<<v.size()<< endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int N;  //numbers of vector
    cin>>N;
    vector<int> v[N];

    for(int i=0;i<N;i++){
        int n;   //size for inside vector
        cin>>n;
        for(int j=0;j<n;j++){ //single vector input
        //jth value in ith vector
            int x;
            cin>>x;
            v[i].push_back(x);  //ith vector
        }
    }
    for(int i=0;i<N;i++){
        print(v[i]);
    }
}