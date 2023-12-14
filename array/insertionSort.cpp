// no swapping only shifting
// what we are doing dividing the array in two parts one is sorted other has randmom element
// then comapre the element and decide will it go to right or left
//why --> adaptable and stable algo
//--> Space Complexity - O(1) --> time complexity O(n2) best case O(n)
#include <iostream>
using namespace std;

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int size)
{
    int j;
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int arr[7] = {10, 1, 7, 4, 8, 2, 11};
    int size = 7;

    insertionSort(arr, size);
    print(arr, size);
}