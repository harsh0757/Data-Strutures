#include<iostream>
#include <climits>
using namespace std;

int maxElement(int arr[], int size){
    int max = INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
int minElement(int arr[], int size){
    int min = INT_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]<min){
           min = arr[i];
        }
    }
    return min;
}

int main(){ 
    int arr[5] = {4,12,8,20,9};
    int size = 5;
    cout<<"Maximum element in array : "<<maxElement(arr, 5) <<endl;
    cout<<"Minimum element in array : "<<minElement(arr, 5) <<endl;
}