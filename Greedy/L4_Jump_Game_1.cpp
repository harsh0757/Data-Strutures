#include<iostream>
using namespace std;

// You are standing at first element and every elements tells to maximum you can jump.
// if you starting at first clement can you reach the last element by jumping.
bool canJump(vector<int>& arr){
    int max_Index = 0;
    for(int i=0;i<arr.size();i++){
        if(i>max_Index) return false;
        max_Index = max(max_Index, i + arr[i]);
    }
    return true;
}

int main(){
    vector<int> arr = {2,3,1,0,4};
    vector<int> arr1 = {3,2,1,0,4};
    if(canJump(arr1)){
        cout<<"We can jump to last index"<<endl;
    } else {
        cout<<"Sorry you cannot jump to last index"<<endl;
    }
}