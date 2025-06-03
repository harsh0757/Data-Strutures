#include<iostream>
using namespace std;

void print(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void leftRotate(vector<int>& arr, int D){

    D = D % arr.size();
//1.Store in temprary variable
    vector<int> temp;
    for(int i=0;i<D;i++){
        temp.push_back(arr[i]);
    }
//2.Shifting of elements
    for(int i=D;i<arr.size();i++){
        arr[i-D] = arr[i];
    }
//3.Put back elements back to the array
    // int j=0;
    for(int i=arr.size() - D;i<arr.size();i++){
        // arr[i] = temp[j];
        arr[i] = temp[i - (arr.size() - D)];
        // j++;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int d = 20;
    leftRotate(arr, d);
    print(arr);
}