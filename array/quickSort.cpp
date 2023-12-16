//take one element put it to right place let a;
//in left part small elements in right part big elements
//    <a |a| >a
//step-->1 partition step-->2 recusrsion
//avg case : o(nlogn)   best case : o(nlogn)   worst case : o(n2)
#include <iostream>
using namespace std;

void print(int *arr, int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int *arr, int s, int e) {
    //store the pivot element
    //count the elements < pivot element then swap with the posititon
    //then take two pointer on start and end then compare with pivot and set according to pivot
    int pivot = arr[s];

    int count = 0;
    for(int i = s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + count;
    swap(arr[pivotIndex],arr[s]);

    //handle left and right part 
    int i=s, j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e){
    //base case
    if(s>=e){
        return;
    }

    //partition 
    int pValue = partition(arr,s,e);

    //left part sort
    quickSort(arr,s,pValue-1);
    //right part sort
    quickSort(arr,pValue+1,e);
}

int main(int argc, char const *argv[])
{
    int arr[7] = {82, 27, 43, 3, 9,38, 10};
    int size = 7;

    quickSort(arr,0,size-1);
    print(arr,size);
    return 0;
}
