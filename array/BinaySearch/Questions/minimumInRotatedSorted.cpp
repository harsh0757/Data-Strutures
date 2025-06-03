#include<iostream>
using namespace std;

// examples
// arr[] = {4,5,6,7,0,1,2}
// arr[] = {7,8,1,2,3,4,5,6}
// arr[] = {4.5,1,2,3}

int findMin(vector<int>& arr){
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while(low <= high){
        int mid = (low + high) / 2;
        //search space is already sorted
        //then always arr[low] will be smaller
        //in that search space
        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }
        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        } else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {4,5,1,2,3};
    cout<<findMin(arr)<<endl;
}