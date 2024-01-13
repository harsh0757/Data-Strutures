#include <bits/stdc++.h>
using namespace std;

// void print(int arr[], int i, int size){
//     if(i==size){
//         return;
//     }
//     print(arr,i+1,size);
//     cout<<arr[i]<<" ";
//     cout<<endl;
// }

// using one pointer approach
//  void reverseOnePointer(int i,int arr[], int n){
//      if(i>=n/2){
//          return;
//      }
//      swap(arr[i], arr[n-i-1]);
//      reverseOnePointer(i+1, arr, n);
//  }

// using two pointer approach
void reversetwoPointer(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    swap(arr[left], arr[right]);
    reversetwoPointer(arr, left + 1, right - 1);
}

int main()
{
    ;
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;
    int left = 0;
    int right = n - 1;
    // reverseOnePointer(0, arr, n);
    reversetwoPointer(arr, left, right);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    // cout<<endl;
    // print(arr,0,n);
}