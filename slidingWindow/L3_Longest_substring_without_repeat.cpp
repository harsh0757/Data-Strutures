#include<iostream>
using namespace std;

//TC --> O(n)  SC --> O(256)
int longestSubstrOp(string s){
    int l = 0, r=0, maxLen = 0;
    int hash[256] = {-1};
    int size = s.length();

    while(r<size){
        if(hash[s[r]] != -1){   //in the map
            if(hash[s[r]] >= l) l = hash[s[r]] + 1;

            int len = r - l + 1;
            maxLen = max(len, maxLen);
            hash[s[r]] = r;
            r++;
        }
    }
    return maxLen;
}

//generate all the substring
int longestSubstr(string s){
    int size = s.length();
    int len = 0, maxlen = 0;
    for(int i=0;i<size;i++){
        // string sub = "";
        int hash[256] = {0};
        for(int j=i;j<size;j++){
            if(hash[s[j]] == 1) break;
            len = j - i + 1;
            maxlen = max(maxlen, len);
            // sub = sub + s[j];
            hash[s[j]] = 1;
        }
    }
    return maxlen;
}

int main(){
    string str = "cadbzabcd";
    cout<<"Length of longest Substring is : "<<longestSubstrOp(str)<<endl;
}