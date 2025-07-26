//find the maximum subarray sum
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//follow-up question
//print the subarray with the maximum sum
int maxsubarraySum_OPE(vector<int>& arr){
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0, ansStart = -1, ansEnd = -1, start = 0;
    for(int i=0;i<n;i++){
        if(sum == 0) start = i;
        sum += arr[i];
        if(sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0) sum = 0;
    }
    if(maxi < 0) maxi = 0;
    //Printing Subarray
    for(int i = ansStart; i <= ansEnd; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return maxi;
}


//TC --> O(n)  SC --> O(1)
int maxsubarraySum_OP(vector<int>& arr){
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum > maxi) maxi = sum;
        if(sum < 0) sum = 0;
    }
    if(maxi < 0) maxi = 0;
    return maxi;
}

//TC --> O(N2)  SC --> O(1)
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
    int maxSum = maxsubarraySum_OPE(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}