#include<iostream>
using namespace std;

void combinationSum2(int index, vector<vector<int>>& ans, vector<int>& arr, vector<int>& ls, int target){
    sort(arr.begin(), arr.end());
        if(target == 0){
            ans.push_back(ls);
            return;
        }
    for(int i=index;i<arr.size();i++){
        //skip duplicates
        if(i>index && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
        ls.push_back(arr[i]);
        combinationSum2(i + 1, ans, arr, ls, target - arr[i]); //i+1 because each element used once
        ls.pop_back();
    }
}

// void combinationSum2(int index, vector<vector<int>>& ans, vector<int>& arr, vector<int>& ls, int target){
//     if(index == arr.size()){
//         if(target == 0){
//             ans.push_back(ls);
//         }
//         return;
//     }
//     if(arr[index] <= target){
//         ls.push_back(arr[index]);
//         combinationSum2(index + 1, ans, arr, ls, target - arr[index]);
//         ls.pop_back();
//     }
//     combinationSum2(index + 1, ans, arr, ls, target);

// }

int main(){
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> ans;
    vector<int> ls;

    combinationSum2(0, ans, arr, ls, 8);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}