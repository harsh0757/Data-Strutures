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

bool linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }
    return false;
}

bool binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}

void bubbleSort(int arr[], int size)
{
    bool swapped = false;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == true)
        {
            break;
        }
    }
}

void selectionSort()
{
}

void insertionSort()
{
}

void spiralPrint()
{
}

void wavePrint()
{
}

void largestRowSum()
{
}

void rowWiseSum()
{
}

int main(int argc, char const *argv[])
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = 10;

    /*bool res = linearSearch(arr,size,6);
    if(res){
        cout<<"Element is present"<<endl;
    }
    else {
        cout<<"Element is not present"<<endl;
    }
    */
    bubbleSort(arr, size);
    printArray(arr, size);
    return 0;
}
