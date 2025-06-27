#include<iostream>
using namespace std;

string reverse(string str){
    int len = str.length();
    int start = 0;
    int end = len - 1;

    while(start <= end){
        swap(str[start++], str[end--]);
    }
    return str;
}

string decimalToBinary(int num){
    string result = "";

    while(num > 0){
        if(num%2 == 1) result += '1';
        else result += '0';
        num = num/2;
    }
    result = reverse(result);
    return result;
}

int main(){
    int num = 13;
    cout<<decimalToBinary(num)<<endl;
}