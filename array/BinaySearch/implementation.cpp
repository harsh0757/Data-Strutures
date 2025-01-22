#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target){

    while(low<=high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;

    }
        return -1;
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    int target = 4;
    int low = 0; int high = 5;

    int result = binarySearch(arr, low, high, target);
    if(result != -1){
        cout<<"Element is present at index : "<<result<<endl;
    } else {
        cout<<"Element is not present"<<endl;
    }
}