#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    cout<<"size of vector : "<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
//similar to array which has dynamic size
//Syntax
// <!----------------------------------------------------------------->
    vector<int> v(5);
    v.push_back(8); //we can extend also
// output
    // 0 0 0 0 0 8
    //vector<int> v;
    // v.push_back(8);  //adds the element in last ---> O(1)
    // v.pop_back(8);  //removes the element from last  --> O(1)
//output
    // 8
    //if we do this
    // vector<int> a(3,4) it wll initialize it with 4
// <!------------------------------------------------------------------>
//input
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     v.push_back(x); //O(1);
    // }
    print(v);
    vector<int> v1 = v;  // we can directly copy the vector in array it is not possible --> O(N)
    //copy vector is expesnive operation we can pass as reference if you are not changing the values
}