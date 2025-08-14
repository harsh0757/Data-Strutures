#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> rightmax(vector<int>& arr){
    vector<int> suffix_max(arr.size());
    suffix_max[arr.size() - 1] = arr[arr.size() - 1];
    for(int i=arr.size()-2;i>=0;i--){
        suffix_max[i] = max(suffix_max[i+1], arr[i]);
    }
    return suffix_max;
}

vector<int> leftmax(vector<int>& arr){
    vector<int> prefix_max(arr.size());
    prefix_max[0] = arr[0];
    for(int i=1;i<arr.size();i++){
        prefix_max[i] = max(prefix_max[i-1], arr[i]);
    }
    return prefix_max;
}

int brute_force(vector<int>& arr){
    vector<int> left = leftmax(arr);
    vector<int> right = rightmax(arr);
    int total = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] < left[i] && arr[i] < right[i]){
            total += min(left[i], right[i]) - arr[i];
        }
    }
    return total;
}

int main(){
    vector<int> arr = {4,5,2,10,8};
    // vector<int> ans = arr;
    int ans = brute_force(arr);
    // for(auto it : ans){
    //     cout<<it<<" ";
    // }cout<<endl;
    cout<<"Maximum unit of water can be stored : "<<ans<<endl;
}