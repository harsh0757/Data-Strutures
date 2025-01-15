#include<iostream>
#include<vector>
using namespace std;

void print(vector<pair<int, int>> v){
    cout<<"Size : "<<v.size()<< endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i].first << " "<<v[i].second<<endl;
    }
    cout<<endl;
}

int main(){
// how to take input
    vector<pair<int, int>> v1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v1.push_back({x,y}); //1st method
        // v1.push_back(make_pair(x,y)); //2nd method
    }
    print (v1);
//declaration of vector with pair
    vector<pair<int,int>> v = {{1,2}, {3,4}, {5,6}};
    print(v);
}