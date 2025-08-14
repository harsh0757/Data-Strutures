#include<iostream>
using namespace std;

void subsetSum2(vector<int>& arr, int index, vector<vector<int>>& ans, vector<int>& ls){
    ans.push_back(ls);
    for(int i=index;i<arr.size();i++){ // base case not required when loop ends it will break through
        //remove duplicates 
        if(i > index && arr[i]==arr[i-1]) continue;
        ls.push_back(arr[i]);
        subsetSum2(arr, i + 1, ans, ls);
        ls.pop_back();
    }
}

int main(){
    vector<int> arr = {1,2,2};
    vector<vector<int>> ans;
    vector<int> ls;
    sort(arr.begin(), arr.end());  // Required to handle duplicates
    subsetSum2(arr, 0, ans, ls);

    for(auto i :  ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}