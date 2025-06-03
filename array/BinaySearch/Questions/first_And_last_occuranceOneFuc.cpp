#include<iostream>
using namespace std;

pair<int, int> first_last(vector<int>& arr, int target) {
    int first = -1;
    int last = -1;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == target){
            if(first == -1) first = i;

            last = i;
        }
    }
    return {first, last};
}

int main(){
     vector<int> arr = {2, 4, 6, 8, 11, 13};
    int target = 4;
    cout << "First and last occurance of " << target << " is : {" << first_last(arr, target).first << ", " << first_last(arr, target).second << "}" << endl;
}