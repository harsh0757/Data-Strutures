#include<iostream>
using namespace std;

char maxoccurance(string s){
    int arr[26] = {0};

//created an array of count characters
    for(int i=0;i<s.length();i++){
        char ch = s[i];

        int number;
        if(ch>='a' && ch<='z'){
            number = ch - 'a';
        } else {
            number = ch - 'A';
        }
        arr[number]++;
    }

    int maxi = 0,  ans = 0;
    for(int i=0;i<26;i++){
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }

    int finalAns = 'a' + ans;
    return finalAns;    
}

int main(){
    string str;
    cin>>str;
    cout<<maxoccurance(str);
    return 0;
}