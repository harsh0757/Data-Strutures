#include<iostream>
using namespace std;

vector<int> brute_force(vector<int> arr){
    vector<int> ans(arr.size(), -1);
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i] < arr[j]){
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {6,0,8,1,3};
    // return {8,8,-1,3,-1};
    vector<int> ans = brute_force(arr);
    for(auto it : ans){
        cout<<it<<" ";
    } cout<<endl;
}