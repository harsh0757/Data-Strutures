#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//maintain the increasing order
//light poles example

// TC--> O(2N)  SC --> (N + N)
vector<int> optimal(vector<int>& arr){
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for(int i=0;i<arr.size();i++){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(!st.empty()) ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

// TC --> O(N2)  SC --> O(N)
vector<int> brute_force(vector<int>& arr){
    vector<int> ans(arr.size(), -1);
    for(int i=0;i<arr.size();i++){
        for(int j = i-1; j>=0; j--){
            if(arr[i]>arr[j]){
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {4,5,2,10,8};
    vector<int> ans = optimal(arr);
    for(auto it : ans){
        cout<<it<<" ";
    }cout<<endl;
}