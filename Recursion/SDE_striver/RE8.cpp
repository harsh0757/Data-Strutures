#include<iostream>
using namespace std;

void combinationSum(vector<int>& arr, int target, int index, vector<int>& ls, vector<vector<int>>& ans){
    if(index == arr.size()){
        if(target == 0) {
            ans.push_back(ls);
        }
        return;
    }
    if(arr[index] <= target) {
        ls.push_back(arr[index]);
        combinationSum(arr, target - arr[index], index, ls, ans);
        ls.pop_back();
    }
    combinationSum(arr, target, index + 1, ls, ans); 
}

int main(){
    vector<int> arr = {2,3,6,7};
    vector<vector<int>> ans;
    vector<int> ls;
    combinationSum(arr, 7, 0, ls, ans);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}