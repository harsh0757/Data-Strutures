#include <bits/stdc++.h>
using namespace std;

int main(){
    string str = "GeeksForGeeks";
    for(int i=0;str[i] != '\0';i++){
        if(islower(str[i])){
            str[i] = toupper(str[i]);
        } else if(isupper(str[i])){
            str[i] = tolower(str[i]);
        }
    }
    cout<<str<<endl;
}