#include<iostream>
using namespace std;

//using dutch national flag alogrithm for optimal approach
//Algorithm is revolving aroung three rules
// 1.Everything from 0 --> low - 1 should be zero i.e. extreme left
// 2.Everything from low --> mid - 1 should be one
// 3.Everything from high + 1 --> n - 1 should be 2 i.e. extreme right

//TC --> O(N)  SC --> O(1)
vector<int> sort_0_1_2_OP(vector<int>& arr){
    int low = 0, high = arr.size() - 1, mid = 0;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if(arr[mid] == 1) mid++;
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return arr;
}


//TC --> O(N)  SC --> O(1)
vector<int> sort_0_1_2(vector<int>& arr){
    int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
    int n = arr.size();

    for(int i=0;i<n;i++){
        if(arr[i] == 0) cnt_0++;
        else if(arr[i] == 1) cnt_1++;
        else cnt_2++;
    }
    for(int i=0;i<cnt_0;i++) arr[i] = 0;
    for(int i=cnt_0;i<cnt_0+cnt_1;i++) arr[i] = 1;
    for(int i=cnt_0 + cnt_1;i<n;i++) arr[i] = 2;

    return arr;
}

int main(){
    vector<int> arr = {0,1,2,0,1,2,1,2,0,0,0,1};
    vector<int> ans = sort_0_1_2_OP(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}