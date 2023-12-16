// different rounds/passes
// smallest element placed to the right position
//use for small size of array
/*first consider the first element as smallest one then store the index in minIndex
if smallest found then swap the index with i;*/
#include <iostream>
using namespace std;

void printAray(int arr[], int size){
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main()
{
    int arr[9] = {29, 72, 98, 13, 87, 66, 52, 51, 36};
    int size = 9;

    cout<<"Doing sorting for you loading....."<<endl;
    selectionSort(arr, size);
    cout<<"Final results :"<<" ";
    printAray(arr, size);
}