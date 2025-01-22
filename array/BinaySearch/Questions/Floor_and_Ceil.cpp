#include<iostream>
using namespace std;

int floor(int arr[], int size, int target){
//largest number in array <= target
    int ans = -1;
    int low = 0; int high = size - 1;

    while(low<=high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] <= target) {
            ans = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int Ceil(int arr[], int size, int target){
// smallest number in array >= target
    int low = 0; int high = size - 1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high - low) / 2;

        if(arr[mid] >= target) {
            ans = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {1,2,3,3,5,8,9,9,9,11};
    // int arr[] = {10,20,30,40,50};
    int target = 100;
    int size = 10;
    cout<<"Floor value for "<<target<< " is "<<floor(arr, size, target)<<endl;
    cout<<"Ceil value for "<<target<< " is "<<Ceil(arr, size, target)<<endl;
}