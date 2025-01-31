#include<iostream>
#include<map>
using namespace std;

int solve(int arr[], int size, int k){
    int l = 0, r =0, maxlen = 0;
    map<int, int> mpp;

    while(r < size){
        mpp[arr[r]]++;
        if(mpp.size() > k){
            mpp[arr[r]]--;
            if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
            l++;
        }
        if(mpp.size() <= k){
            maxlen = max(maxlen, r-l+1);
        }
        r++;
    }
    return maxlen;
}

int main(){
    int arr[] = {3,3,3,1,2,2,1,2,3,3,4};
    int size = 11;
    int k = 2;
    cout<<solve(arr, size, k)<<endl;
}