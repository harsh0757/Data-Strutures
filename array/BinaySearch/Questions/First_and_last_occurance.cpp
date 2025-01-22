#include <iostream>
using namespace std;

int lowerBound(int arr[], int size, int x)
{
    int high = size - 1;
    int low = 0;
    int ans = size;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(int arr[], int size, int x)
{
    int high = size - 1;
    int low = 0;
    int ans = size;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(int arr[], int target, int size)
{
    int lb = lowerBound(arr, size, target);
    if (lb == size || arr[lb] != target) return {-1, -1};
    return {lb, upperBound(arr, size, target) - 1};
}

int main()
{
// TC --> 2 * O(logN)
// SC --> O(1)
    int arr[] = {2, 4, 6, 8, 8, 8, 11, 13};
    int target = 8;
    int size = 8;
    cout << "First and last occurance of " << target << " is : {" << firstAndLastPosition(arr, target, size).first << ", " << firstAndLastPosition(arr, target, size).second << "}" << endl;
}