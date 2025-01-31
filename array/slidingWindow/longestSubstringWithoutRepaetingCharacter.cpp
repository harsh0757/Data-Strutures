#include<iostream>
using namespace std;

int solve(string str){
    int l=0, r=0, maxlen = 0;
    int size = str.size();
    int hash[256];
    for(int i=0;i<256;i++){
        hash[i] = -1;
    }

    while(r < size){
        if(hash[str[r]] != -1){
            if(hash[str[r]] >= l){
                l = hash[str[r]] + 1;
            }
        }
        int len = r - l + 1;
        maxlen = max(len, maxlen);
        hash[str[r]] = r;
        r++;
    }
    return maxlen;
}

int main(){
    string str = "cadbzabcd";
    cout<<solve(str)<<endl;
}