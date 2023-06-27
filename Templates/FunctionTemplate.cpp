#include <iostream>
using namespace std;

template <typename T> T Max(T x, T y){
    return (x>y) ? x : y;
}

template <typename T> void bubblesort(T arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;i<j;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
}

int main(){
    int arr[5] = {10,30,55,23,15};
    int n = 5;
    bubblesort<int>(arr,n);
    cout<<"Sorted array : ";

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<Max<int>(3, 5)<<endl;
}