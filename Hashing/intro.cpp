// givrn an array count the frequencies of numbers

#include<iostream>
using namespace std;

int for_char(char c, string s){
    int cnt = 0;
    for(int i=0;i<s.length();i++){
        if(c == s[i]){
            cnt++;
        }
    }
    return cnt;
}

// TC --> O(Q * N)  ->> Q is toatal numbers to count
int brute(vector<int>& arr, int num){
    int cnt = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == num){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    vector<int> arr = {1,2,1,3,2};
    int num = 2;
    cout<<"Number of times "<<num<<" occurred is : "<<brute(arr, num)<<endl;
    string s = "abcdabefc";
    char c = 'a';
    cout<<"Number of times "<<c<<" occurred is : "<<brute(arr, num)<<endl;
    for_char(c, s);
}