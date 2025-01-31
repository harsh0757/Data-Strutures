#include<iostream>
using namespace std;

int solve(int arr[], int k, int size){
    int zeroes = 0, maxlen = 0, l=0, r=0;
    while(r < size){
        if(arr[r] == 0) zeroes++;
        if(zeroes > k){ //(keeping the length maximum we can use  while loop here also that will give complexity to O(2N)
            if(arr[l] == 0) zeroes--;
            l++;
        }
        if(zeroes <= k){
            int len = r - l + 1;
            maxlen = max(len, maxlen);
        }
        r++;
    }
    return maxlen;
}

int main(){
    int arr[] = {1,1,1,1,0,0,0,0,1,1,1,1,1,1,0};
    int size = 15;
    int k = 2;
    cout<<solve(arr, k, size)<<endl;
}