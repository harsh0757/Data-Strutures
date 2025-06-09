#include <iostream>
using namespace std;

int maxPoint(vector<int>& arr, int k){
    int lsum = 0, maxSum = 0, rsum = 0;

    // if(k>arr.size()) return -1;

    for(int i=0;i<k;i++) lsum = lsum + arr[i];
    maxSum = lsum;

    int rightIndex = arr.size() - 1;
    for(int i=k-1;i>=0;i--){
        lsum = lsum - arr[i];
        rsum = rsum + arr[rightIndex];
        rightIndex--;

        maxSum = max(maxSum, lsum + rsum);
    }
    return maxSum;
}

int main(){
    vector<int> arr = {6,2,3,4,7,2,1,7,1};
    int k = 4;
    cout<<"Max Point you can collect is : "<<maxPoint(arr, 4)<<endl;
}