//find the maximum subarray sum
#include<iostream>
#include<vector>
using namespace std;

int maxSubarraySum_BE(vector<int>& arr){
    //we don't need to re-iterate add the next element eventually you get the sum of the subarray
    int n = arr.size();
    int maxi = INT_MIN;

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}

//TC --> O(N3) O(1)
int maxSubarraySum(vector<int> arr){
    int maxi = INT_MIN;
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += arr[k];
            }
            maxi = max(maxi,sum);
        }
    }
    return maxi;
}

int main(){
    vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};
    int maxSum = maxSubarraySum_BE(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}