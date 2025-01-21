#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int> previousSmallerElement(vector<int> nums){
        int size = nums.size();
        vector<int> pse(size, -1);
        stack<int> st;
        for(int i=0;i<size;i++){
            while(!st.empty() && st.top() >= nums[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        return pse;
    }
};

int main(){
    Solution obj;
    vector<int> v = {4,5,2,10,8};
    vector<int> res = obj.previousSmallerElement(v);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout<<endl;
}