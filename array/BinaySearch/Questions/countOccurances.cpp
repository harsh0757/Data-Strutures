#include <iostream>
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


pair<int, int> firstAndLastPosition(int arr[], int target, int size)
{
    int first = firstOccurance(arr, size, target);
    if (first == -1) return {-1, -1};
    int last  = lastOccurance(arr, size, target);
    return {first, last};
}

int main()
{
    int arr[] = {2, 4, 6, 8, 8, 8, 11, 13};
    int target = 8;
    int size = 8;
    pair<int, int> ans = firstAndLastPosition(arr, target, size);
    if(ans.first == -1) return 0;
    cout<<"Total number of occurances for : "<< target <<" is : "<<ans.second - ans.first + 1<<endl;
}