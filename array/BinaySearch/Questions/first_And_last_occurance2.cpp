#include <iostream>
using namespace std;

int firstOccurance(vector<int>& arr, int target){
    int high = arr.size() - 1, low = 0;
    int first = -1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target){
            first = mid;
            high = mid - 1;
        } else if(arr[mid] < target){  
            low = mid + 1;  
        }else {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurance(vector<int>& arr , int target){
    int high = arr.size() - 1; int low = 0;
    int last = -1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target){
            last = mid;
            low = mid + 1;  //need first occurance so will go left and see
        } else if(arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr , int target)
{
    int first = firstOccurance(arr, target);
    if (first == -1) return {-1, -1};
    int last  = lastOccurance(arr, target);
    return {first, last};
}

int main()
{
// TC --> O(logN)
// SC --> O(1)
    vector<int> arr = {2, 4, 6, 8, 11, 13};
    int target = 13;
    cout << "First and last occurance of " << target << " is : {" << firstAndLastPosition(arr, target).first << ", " << firstAndLastPosition(arr, target).second << "}" << endl;
}