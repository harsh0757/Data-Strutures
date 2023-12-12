// largest element to right position
// evert ith round we will position the ith largest element
//Best case - o(n);
//worst case - o(n2);
#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int size)
{
    bool swapped = false;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
        }
        if (swapped == false)
            //already sorted
            break;
    }
}

int main()
{
    int arr[9] = {29, 72, 98, 13, 87, 66, 52, 51, 36};
    int size = 9;

    bubbleSort(arr, size);
    printArray(arr, size);
}