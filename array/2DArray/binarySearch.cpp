#include<iostream>
using namespace std;

bool binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while(low<=high){
        int mid  = (low + high)/2;

        if(arr[mid] == target) {
            cout<<"Element is present at index : "<< mid <<endl;
            return mid;
        }else if(target > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    cout<<"Element is not present "<<endl;
    return -1;
}

int main(){
    int arr[8] = {3,4,6,7,9,12,16,17};
    int target = 16;
    int size = 8;
    binarySearch(arr, size, target);
}