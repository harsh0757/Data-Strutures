#include<iostream>
#include<climits>
using namespace std;

int min_Jump_optimal(vector<int>& arr){
    int jumps = 0, l=0, r=0;
    while(r < arr.size() - 1){
        int farthest = 0;
        for(int i=l;i<=r;i++){
            farthest = max(i + arr[i], farthest);
        }
        l = r + 1;
        r = farthest;
        jumps = jumps + 1;
    }
    return jumps;
}

int min_Jump(vector<int>& arr, int index, int jumps){
    if(index >= arr.size() - 1) return jumps;

    int mini = INT_MAX;
    if(arr[index] == 0) return INT_MAX;
    for(int i=1;i<=arr[index];i++){
        mini = min(mini, min_Jump(arr, index + i, jumps + 1));
    }
    return mini;
}

int main(){
    vector<int> arr = {2,3,1,4,1,1,1,2};
    int start = 0;
    int jumps = 0;
    // if(min_Jump(arr, start, jumps) == INT_MAX) cout<<"Not reachable"<<endl;
    cout<<min_Jump_optimal(arr)<<endl;
}