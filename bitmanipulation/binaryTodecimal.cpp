#include<iostream>
using namespace std;

int binaryTodecimal(string str){
    int len = str.length();
    int num = 0;
    int p2 = 1;
    for(int i = len - 1; i >= 0; i--){
        if(str[i] == '1'){
            num = num + p2;
        }
        p2 *= 2;
    }
    return num;
}

int main(){
    string str = "1101";
    cout<<binaryTodecimal(str)<<endl;
}