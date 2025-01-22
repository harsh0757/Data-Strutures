#include<iostream>
using namespace std;

int upperBound(int arr[], int size, int x){
    int high = size - 1; int low = 0;
    int ans = size;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] > x) {
            ans = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    int arr[] = {1,2,3,3,5,8,9,9,9,11};
    int target = 11;
    int size = 10;
    cout<<"The upper bound for the target "<<target<< " is "<<upperBound(arr, size, target)<<endl;
}