#include <iostream>
using namespace std;

bool binarySearch(int arr[][4], int row, int col, int target)
{
    int start = 0;
    int end = (row * col) - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int element = arr[mid/col][mid%col];
        if (element == target)
        {
            return true;
        }

        if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    mid = start + (end - start) / 2;
    }
    return 0;
}

int main()
{
    int arr[3][4] = {1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 60};

    if(binarySearch(arr,3,4,61)){
        cout<<"Element is present"<<endl;
    } else {
        cout<<"Element is not present"<<endl;
    }

    return 0;
}
