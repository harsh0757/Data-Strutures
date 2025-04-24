#include<iostream>
#include<vector>
#include <set>
using namespace std;

int optimal(vector<int> &arr){
    int i=0;
    for(int j=1;j<arr.size();j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}

int removeDuplicates(vector<int> &arr){
    set<int> st;
    for(int i=0;i<arr.size()-1;i++){
        st.insert(arr[i]);
    }
    int index = 0;
    for(auto it : st){
        arr[index] = it;
        index++;
    }
    return index;
}

int main(){
    vector<int> arr = {1,1,2,2,2,3,3};
    // cout<<removeDuplicates(arr)<<endl;
    cout<<optimal(arr)<<endl;
}