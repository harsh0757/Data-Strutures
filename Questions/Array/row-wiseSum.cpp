#include <iostream>
using namespace std;

void sumRow(int arr[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = 0; j < size; j++)
        {
            sum += arr[i][j];
        }
        cout<< "sum of row " << i << ": "<<sum << endl;
    }
}
void sumCol(int arr[][3], int size)
{
    for (int j = 0; j < size; j++)
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr[i][j];
        }
        cout<< "sum of col " << j << ": "<<sum << endl;
    }
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
    sumRow(arr,size);
    sumCol(arr,size);
    return 0;
}
