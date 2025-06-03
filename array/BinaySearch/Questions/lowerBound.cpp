#include<iostream>
using namespace std;

//smallest index such that arr[index] >= x
                            //will get iterator pointing to index     //after subtracting the begin iterator will get the index
// use the stl function lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin()

int lowerBound(int arr[], int size, int x){
    int high = size - 1; int low = 0;
    int ans = size; //if there is no answer possible i will always return last hypothetical index
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= x) {
            ans = arr[mid];
            high = mid - 1; // smaller will be on left
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    int arr[] = {1,2,3,3,5,8,9,9,9,11};
    int target = 5;
    int size = 10;
    cout<<"The Lower bound for the target "<<target<< " is "<<lowerBound(arr, size, target)<<endl;
}