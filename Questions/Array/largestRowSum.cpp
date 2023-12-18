#include <iostream>
#include <climits>
using namespace std;

int largestRowSum(int arr[][3], int size){
    int max = INT_MIN;
    int rowIndex = -1;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = 0; j < size; j++)
        {
            sum += arr[i][j];
        }
        if(sum>max){
            max = sum;
            rowIndex = i;
        }
    }
    cout<<"The maximum row sum is : "<<max<<endl;
    return rowIndex;
}

int main(int argc, char const *argv[])
{
    int arr[3][3] = {0};
    int size = 3;

    cout << "Enter the elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }
    int rowIndex = largestRowSum(arr,3);
    cout<<"Max row index : "<<rowIndex<<endl;
    return 0;
}
