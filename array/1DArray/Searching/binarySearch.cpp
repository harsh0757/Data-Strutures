//binary search will apply on
//monotonus function -->increasing or decreasing order

//first step --> Find mid element
//Second step --> comapare mid element with key
//third step --> if equal return index else which part to search 
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    int mid = start +(end-start)/2;

   while(start<=end){
    if(arr[mid] == key){
        return mid;
    }
    if(key > arr[mid]) {
        start = mid+1;
    } else {
        end = mid - 1;
    }
   mid = start +(end-start)/2;
   }
   return -1;
}
int main(){
    int key;
    cin>>key;
    int arr[5] = {3,5,9,13,27};
    int brr[6] = {3,5,9,12,13,35};
    int size = 5;

    cout<<"Key is at index number : "<<binarySearch(arr, size, key)<<endl;
    cout<<"(for even)Key is at index number : "<<binarySearch(brr, 6, key)<<endl;

}
