#include<iostream>
using namespace std;

char isAlphaNum(char ch){
    return (ch >= 'A' && ch <='Z') ||
           (ch >= 'a' && ch <='z') ||
           (ch >= '0' && ch <='9');
}

char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    } else {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool palindrome(vector<char> name){
    int start = 0;
    int end = name.size() - 1;

    while(start <= end){
        
        if(!isAlphaNum(name[start])){
            start++;
            continue;
        }
        if(!isAlphaNum(name[end])){
            end--;
            continue;
        }

        if(toLowerCase(name[start]) != toLowerCase(name[end])){
            return false;
        }

        start++;
        end--;
    }
    return true;
}

int main(){
    string input;
    cin>>input;
    vector<char> name(input.begin(), input.end());
    if(palindrome(name)){
        cout<<"String is palindrome"<<endl;
    } else {
        cout<<"String is not a palindrome"<<endl;
    }
}