#include<iostream>
using namespace std;

void print(vector<int>& arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool palindrome(string& str, int i, int j){
    if(i>=j) return true;
    if(str[i] != str[j]) return false;
    return palindrome(str, i+1, j-1);
}

vector<int> reverse(vector<int>& arr, int i, int j){
    if(i>=j) return arr;
    swap(arr[i], arr[j]);
    return reverse(arr, i+1, j-1);
}

// void reverse(vector<int>& arr, int i, int j){
//     if(i>j) return;
//     swap(arr[i], arr[j]);
//     reverse(arr, i+1, j-1);
// }

int main(){
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    print(arr, n);
    vector<int> ans = reverse(arr, 0, n-1);
    print(ans, n);

    string str = "abcda";
    if(palindrome(str, 0, str.length() - 1)){
        cout<<"String is a palidrome";
    } else {
        cout<<"String is not a palindrome"<<endl;
    }
    return 0;
}