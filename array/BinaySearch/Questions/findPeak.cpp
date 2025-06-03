#include<iostream>
using namespace std;

int findPeak(vector<int>& arr){
    int low = 0;
    int high = arr.size() - 1;

    while(low < high){
        int mid  = (low + high) / 2;
        if(arr[mid] > arr[mid + 1]){
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    cout<<findPeak(nums)<<endl;
}