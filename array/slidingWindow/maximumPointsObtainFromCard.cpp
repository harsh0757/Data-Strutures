#include<iostream>
using namespace std;

int solve(int arr[], int size, int k){
    int lsum = 0, rsum = 0, maxSum = 0;
    for(int i=0;i<=k-1;i++){
        lsum = lsum + arr[i];
        maxSum = lsum;
    }
    int rIndex = size - 1;
    for(int i = k-1;i>=0;i--){
        lsum = lsum - arr[i];
        rsum = rsum + arr[rIndex];
        rIndex--;
        maxSum = max(maxSum, lsum + rsum);
    }
    return maxSum;
}

int main(){
    int arr[] = {6,2,3,4,7,2,1,7,1};
    int k = 4;
    int size = 9;
    cout<<solve(arr, size, k)<<endl;
}