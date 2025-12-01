#include<iostream>
using namespace std;

void reverse(string str){
    int length = str.length();
    int start = 0;
    int end = length - 1;

    while(start < end){
        swap(str[start++], str[end--]);
    }
}

string convert_to_decimal(int n){
    string res = "";
    while(n > 0){
        if(n%2 == 1) res += '1';
        else res += '0';

        n = n/2;
    }
    reverse(res);
    return res;
}

int main(){
    int n;
    cin>>n;
    cout<<convert_to_decimal(n)<<endl;
}