#include<iostream>
using namespace std;

int lastOccurance(int arr[], int size, int target){
    int high = size - 1; int low = 0;
    int last = -1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target){
            last = mid;
            low = mid + 1;  //need first occurance so will go left and see
        } else {
            high = mid - 1;
        }
    }
    return last;
}

int main(){
    int arr[] = {2,8,8,8,8,8,11,13};
    int size = 8;
    int target = 8;
    cout<<"Last occurance of "<< target << " is at index : " <<lastOccurance(arr,size,target)<<endl;
}