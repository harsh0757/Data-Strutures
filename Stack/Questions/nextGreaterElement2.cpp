#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int> nextGreaterElement(vector<int>& nums){
        int size = nums.size();
        stack<int> st;
        vector<int> nge(size, -1);
        for(int i=0;i<size;i++){ 
            for(int j= i+1;j<size+i-1;j++){
                int ind = j%size;
                if(nums[ind] > nums[i]){
                    nge[i] = nums[ind];
                    break;
                }
            }
        }
        return nge;
    }
};
// 2nd approach
// TC --> O(4N)  because while loop is not running everytime to O(4N)
// SC --> O(2N)
class Solution1{
public:
    vector<int> nextGreaterElement(vector<int>& nums){
        int size = nums.size();
        stack<int> st;
        vector<int> nge(size, -1);
        for(int i=2*size - 1; i>=0; i--){ 
            while(!st.empty() && st.top() <= nums[i%size]){
                st.pop();
            }
            if(i<size){
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i%size]);
        }
        return nge;
    }
};

int main(){
  Solution1 obj;
  vector <int> v {5,7,1,2,6,0};
  vector <int> res = obj.nextGreaterElement(v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
  cout<<endl;
}