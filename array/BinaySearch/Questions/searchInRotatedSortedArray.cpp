#include<iostream>
using namespace std;

//aproach
//identify the sorted half left or right
int Solve(vector<int>& arr, int target){
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target) return mid;

        //identify the sorted half
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){ //target is greater than low and lesser than mid
                high = mid - 1;
            } else low = mid + 1;
        } else {
            if(arr[high] >= target && arr[mid] <= target){ //target is lesser than high and greater than mid
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {7,8,9,1,2,3,4,5,6};
    int result = Solve(arr, 4);
    if(result != -1){
        cout<<"Number is present at : " << result << "th index"<<endl;
    } else {
        cout<<"Number is not present"<<endl;
    }
}