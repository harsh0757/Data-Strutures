#include<iostream>
using namespace std;

void print(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void leftRotate(vector<int>& arr){
    int temp = arr[0];
    for(int i=1;i<arr.size();i++){
        arr[i-1] = arr[i];
    }
    arr[arr.size() - 1] = temp;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    leftRotate(arr);
    print(arr);
}