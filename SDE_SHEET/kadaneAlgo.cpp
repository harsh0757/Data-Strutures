// find the maximum subarray sum
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int printMinSubarray(vector<int> &arr){
    int n = arr.size();
    int mini = INT_MAX;
    int sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i; // start with new index will not find thr ans with sum 0 we have to find maximum

        sum += arr[i];

        if (sum < mini) {
            mini = sum;

            ansStart = start;
            ansEnd = i;
        }
        // if sum < 0 discard the sum
        if (sum > 0) sum = 0;
    }
    // print subarray
    for (int i = ansStart; i <= ansEnd; i++) cout << arr[i] << " ";
    cout << endl;

    return mini;
}

// follow-up question print the max length of subarray
// There might be more than one subarray with the maximum sum. We need to print any of them.

int printMaxSubarray(vector<int> &arr){
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i; // start with new index will not find thr ans with sum 0 we have to find maximum

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }
        // if sum < 0 discard the sum
        if (sum < 0) sum = 0;
    }
    // print subarray
    for (int i = ansStart; i <= ansEnd; i++) cout << arr[i] << " ";
    cout << endl;

    return maxi;
}

int kadane_Algo(vector<int> &arr) {
    int n = arr.size();
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > maxi) maxi = sum;
        if (sum < 0) sum = 0;
    }
    return maxi;
}

int maxSubarraySum_BE(vector<int> &arr) {
    // we don't need to re-iterate add the next element eventually you get the sum of the subarray
    int n = arr.size();
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}

// TC --> O(N3) O(1)
int maxSubarraySum(vector<int> arr) {
    int maxi = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int maxSum = printMaxSubarray(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}