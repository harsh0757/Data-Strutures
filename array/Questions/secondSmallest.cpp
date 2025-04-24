#include<iostream>
using namespace std;

int ssmallest(vector<int>& arr){
    int smallest = arr[0];
    int ssmallest = INT_MAX;

    for(int i=0;i<arr.size();i++){
        if(arr[i] < smallest){
            ssmallest = smallest;
            smallest = arr[i];
        } else if(arr[i] > smallest && arr[i] < ssmallest){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

int main(){
    vector<int> arr = {5, 2, 1, 11, 45, 78, 20};
    cout << "The Second Largest element in the array is: " << ssmallest(arr) << endl;
}
