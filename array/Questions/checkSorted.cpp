#include<iostream>
using namespace std;

bool checkSorted(vector<int>& arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i] >= arr[i-1]){
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> arr = {1, 2, 1, 4, 5}; 
    if (checkSorted(arr)) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }

    return 0;
}