#include<iostream>
using namespace std;

void print_all_permutation(vector<int>& arr, vector<int>& ls, vector<vector<int>>& ans, vector<int>& freq){
    if(ls.size() == arr.size()){
        ans.push_back(ls);
        return;
    }
    for(int i=0;i<arr.size();i++){
        if(!freq[i]){
            ls.push_back(arr[i]);
            freq[i] = 1;
            print_all_permutation(arr, ls, ans, freq);
            freq[i] = 0;
            ls.pop_back();
        }

    }
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> ls;
    vector<int> freq(arr.size(), 0);
    
    print_all_permutation(arr, ls, ans, freq);

    for(auto i :  ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}