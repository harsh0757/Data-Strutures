#include<iostream>
using namespace std;

int firstOccurance(int arr[], int size, int target){
    int high = size - 1; int low = 0;
    int first = -1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target){
            first = mid;
            high = mid - 1;  //need first occurance so will go left and see
        } else {
            low = mid + 1;
        }
    }
    return first;
}

int main(){
    int arr[] = {2,8,8,8,8,8,11,13};
    int size = 8;
    int target = 8;
    cout<<"First occurance of "<< target << " is at index : " <<firstOccurance(arr,size,target)<<endl;
}