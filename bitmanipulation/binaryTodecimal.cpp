#include<iostream>
using namespace std;

int binaryTodecimal(string str){
    int len = str.length();
    int p2 = 1;
    int num = 0;
    for(int i=len-1;i>=0;i--){
        if(str[i] == '1'){
            num = num + p2;
        }
        p2 = p2 * 2;
    }
    return num;
}

int main(){
    string str = "1010";
    cout<<binaryTodecimal(str)<<endl;
}