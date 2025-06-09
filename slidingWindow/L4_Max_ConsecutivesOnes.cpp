#include<iostream>
using namespace std;

//TC --> O(N)  SC--> O(1)
int maxConsOp(vector<int>& arr, int k){
    int maxlen = 0, l=0,r=0, zeroes = 0;
    while(r<arr.size()){
        if(arr[r] == 0) zeroes++;
        if(zeroes > k){
            if(arr[l] == 0){
                zeroes--;
            }
            l++;
        }
        if(zeroes <= k){
            int len = r-l+1;
            maxlen = max(len, maxlen);
        }
        r++;
    }
    return maxlen;
}

//TC --> O(N + N)  SC--> O(1)
int maxConsbe(vector<int>& arr, int k){
    int maxlen = 0, l=0,r=0, zeroes = 0;
    while(r<arr.size()){
        if(arr[r] == 0) zeroes++;
        while(zeroes > k){
            if(arr[l] == 0){
                zeroes--;
            }
            l++;
        }
        if(zeroes <= k){
            int len = r-l+1;
            maxlen = max(len, maxlen);
        }
        r++;
    }
    return maxlen;
}

//Question --> Max consecutive ones III allowed to flip at most k zeroes
//can convert to longest subarray with atmost K zeroes  

// TC --> O(N2)  SC --> O(1)
int maxCons(vector<int>& arr, int k){
    int maxlen = 0;
    for(int i=0;i<arr.size();i++){
        int zeroes = 0;
        for(int j=i;j<arr.size();j++){
            if(arr[j] == 0) zeroes++;
            if(zeroes<=k){
                int len = j - i + 1;
                maxlen = max(len, maxlen);
            } else break;
        }
    }
    return maxlen;
}

int main(){
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<maxConsOp(arr, k)<<endl;
}