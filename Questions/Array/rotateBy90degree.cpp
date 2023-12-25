#include <iostream>
using namespace std;

void rotateArray(int arr[][3], int size)
{
    for (int j = 0; j < size; j++)
    {
        for (int i = size-1; i >= 0; i--)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};
    int size = 3;

    rotateArray(arr, size);
}