#include <iostream>
using namespace std;
//print subsequence
void print(vector<int>& temp){
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}

void printSubsequence(vector<int>& arr, int index, vector<int>& temp){
    if(index >= arr.size()){
        print(temp);
        return;
    }
    temp.push_back(arr[index]);
    printSubsequence(arr, index + 1, temp);
    temp.pop_back();
    printSubsequence(arr, index + 1, temp);
}

int main(){
    vector<int> arr = {3,1,2};
    vector<int> temp;

    printSubsequence(arr, 0, temp);
}