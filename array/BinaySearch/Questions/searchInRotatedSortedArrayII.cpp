#include<iostream>
using namespace std;

int Solve(vector<int>& arr, int target){
    int low = 0, high = arr.size() - 1;

    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target) return mid;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++, high--;
            continue;
        }

        if(arr[low] <= mid){
            if(arr[low] <= mid && arr[mid] >= target) {
                high = mid - 1;
            } else low = mid + 1;
        } else {
            if(arr[high] >= mid && target >= arr[mid]){
                low = mid + 1;
            } else high = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {3,1,2,3,3,3,3};
    int target = 2;
    int result = Solve(arr, target);
    if(result != -1){
        cout<<"Number is present"<<result<<endl;
    } else {
        cout<<"Number is not present"<<endl;
    }
}