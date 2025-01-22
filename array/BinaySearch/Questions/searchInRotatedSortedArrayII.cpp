#include<iostream>
using namespace std;

int Solve(int arr[], int size, int target){
    int high = size - 1; int low = 0;
    while(low<=high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid;
        if(arr[mid] == arr[low] && arr[mid] == arr[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }
        if(arr[low] <= arr[mid]){
            if(target >= arr[low] && target <= arr[mid]) high = mid - 1;
            else low = mid + 1;
        } else {
            if(target >= arr[mid] && target <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {3,1,2,3,3,3,3};
    int target = 1;
    int size = 7;
    int result = Solve(arr, size, target);
    if(result != -1){
        cout<<"Number is present"<<endl;
    } else {
        cout<<"Number is not present"<<endl;
    }
}