#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int optimal(vector<int>& arr){
    int size = arr.size();
    int max = arr[0];
        for(int i=0;i<size;i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
    return max;
}

int findLargest(vector<int> arr){
    //passing by value also take O(N) as a space complexity
    int size = arr.size();
    sort(arr.begin(), arr.end());

    return arr[size - 1];
}

int main(){
    vector<int> arr = {1,2,4,11,45,78,20};
    cout<<"The Largest element in the array is: "<<optimal(arr)<<endl;
}