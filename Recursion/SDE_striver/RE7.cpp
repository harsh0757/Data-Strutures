#include<iostream>
using namespace std;

//print subsequence with sum k

void print(vector<int>& temp){
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}

void printSubsequence_with_sum_k(vector<int>& arr, vector<int>& temp, int sum, int index, int k){
    if(index == arr.size()){
        if(sum == k){
            print(temp);
        }
        return;
    }
    temp.push_back(arr[index]);
    printSubsequence_with_sum_k(arr, temp, sum + arr[index], index + 1, k);
    temp.pop_back();
    printSubsequence_with_sum_k(arr, temp, sum, index + 1, k);
}

int main(){
    vector<int> arr = {3,1,2};
    vector<int> temp;
    printSubsequence_with_sum_k(arr, temp, 0, 0, 5);
}