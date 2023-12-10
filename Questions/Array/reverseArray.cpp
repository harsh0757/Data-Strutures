#include <iostream>
using namespace std;

void print(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void arrayReverse(int arr[], int size){
    int i = 0;
    int j = size-1;

    while(i<=j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;j--;
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    cout<<"Reversing the array : ";
    // for(int i=size-1;i>=0;i--){
    //     cout<<arr[i]<<" ";
    // }

    arrayReverse(arr, size);
    print(arr,size);
}