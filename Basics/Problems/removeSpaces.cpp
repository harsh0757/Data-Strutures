#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "Gfg to the moon";
    string result;
    
    for(int i=0;str[i]!='\0';i++){
        if(str[i] != ' '){
            result+=str[i];
        }
    }
    cout<<result<<endl;
}