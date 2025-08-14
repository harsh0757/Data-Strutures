#include<iostream>
using namespace std;

void subsetSum(int index, vector<int>& arr, int sum, vector<int>& ls){
    if(index == arr.size()){
        ls.push_back(sum);
        return;
    }
    subsetSum(index + 1, arr, sum + arr[index], ls);
    subsetSum(index + 1, arr, sum, ls);
}

int main(){
    vector<int> arr = {2,3};
    vector<int> ls;
    subsetSum(0, arr, 0, ls);
    sort(ls.begin(), ls.end());

    for(auto it : ls){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}