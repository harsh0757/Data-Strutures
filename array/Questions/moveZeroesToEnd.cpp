#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& ans){
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

vector<int> optimal(vector<int>& arr){
    int j = -1;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }

    for(int i = j+1;i<arr.size();i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j++]);
        }
    }
    return arr;
}

vector<int> moveZeroes(vector<int>& arr){
    vector<int> temp;
    for(int i=0;i<arr.size();i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }

    for(int i=0;i<arr.size();i++){
        if(arr[i] == 0){
            temp.push_back(arr[i]);
        }
    }
    return temp;
}

int main(){
    vector<int> arr = {1,2,0,0,0,3,4,5};
    vector<int> ans = optimal(arr);
    print(ans);
}