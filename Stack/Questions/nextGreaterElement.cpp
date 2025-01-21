#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// TC --> O(2N)  because while loop is not running everytime to O(N )
class Solution{
public:
    vector<int> nextGreaterElement(vector<int>& nums){
        int size = nums.size();
        stack<int> st;
        vector<int> nge(size, -1);
        for(int i=size-1;i>=0;i--){ 
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty()) nge[i] = -1;  //no elements greater than current element
            else nge[i] = st.top();

            st.push(nums[i]);
        }
        return nge;
    }
};

int main(){
  Solution obj;
  vector <int> v {5,7,1,2,6,0};
  vector <int> res = obj.nextGreaterElement(v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
}