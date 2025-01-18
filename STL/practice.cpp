#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<int> v) {
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v  = {3,4,2,5,6,9};
    sort(v.begin(), v.end()); //ascending order
    print(v);
    sort(v.begin(), v.end(), std::greater<int>()); //descending order
    print(v);
    sort(v.begin(), v.end(), std::greater<int>()); //descending order
    return 0;
}