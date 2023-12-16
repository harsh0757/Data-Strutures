// divide and conquer
// recursively implement
// approaches 1.create new array and copy values 2.use indexes
///applications, inversion count problem solve, use indexes to solve
#include <iostream>
using namespace std;

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex];
        mainArrayIndex++;
    }
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex];
        mainArrayIndex++;
    }

    // merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex] = first[index1];
            mainArrayIndex++;
            index1++;
        }
        else
        {
            arr[mainArrayIndex] = second[index2];
            mainArrayIndex++;
            index2++;
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex] = first[index1];
        mainArrayIndex++;
        index1++;
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex] = second[index2];
        mainArrayIndex++;
        index2++;
    }
    delete []first;
    delete []second;
}

void mergeSort(int *arr, int start, int end)
{
    // base case
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    // sort left part
    mergeSort(arr, start, mid);

    // sort right part
    mergeSort(arr, mid + 1, end);

    // merge
    merge(arr, start, end);
}

int main(int argc, char const *argv[])
{
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};
    int size = 7;

    mergeSort(arr, 0, size - 1);
    print(arr, size);
    return 0;
}
