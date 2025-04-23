#include<iostream>
using namespace std;

void reverseWords(string str){
    string word = "";

    for(int i=0;i<=str.length();i++){
        if(str[i] == ' ' || str[i] == '\0'){
            int start = 0;
            int end = word.length() - 1;

            while(start<end){
                swap(word[start++], word[end--]);
            }

            cout<<word;
            if(str[i] != '\0'){
                cout<<" ";
            }

            word = "";
        } else {
            word += str[i];
        }
    }
}

int main(){
    string sentence;
    getline(cin, sentence);
    reverseWords(sentence);
}