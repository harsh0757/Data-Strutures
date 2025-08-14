#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> optimal(vector<int>& arr){
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n, -1);

    for(int i=2*n - 1; i>=0; i--){
        int curr = arr[i%n];
        while(!st.empty() && st.top() <= curr){
            st.pop();
        }
        if(i<n) ans[i] = st.empty() ? -1 : st.top();

        st.push(curr);
    }
    return ans;
}

// TC --> O(N2)  SC --> O(N)
vector<int> brute_force(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n, -1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<i+n-1;j++){
            int index = j%n;
            if(arr[index] > arr[i]){
                ans[i] = arr[index];
                break;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2,10,12,1,11};
    vector<int> ans = optimal(arr);
    for(auto it : ans){
        cout<<it<<" ";
    }cout<<endl;
}