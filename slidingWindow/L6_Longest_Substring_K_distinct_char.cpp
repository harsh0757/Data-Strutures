#include<iostream>
#include<map>
#include<set>
using namespace std;

int longest_substr_Be(string s, int k){
    int maxlen = 0, l=0, r=0;
    map<char, int> mpp;
    
    while(r<s.length()){
        mpp[s[r]]++;
        while(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }
        if(mpp.size() <= k)maxlen = max(maxlen, r-l+1);
        r++;
    }
    return maxlen;
}

int longest_substr(string s, int k){
    int maxlen = 0;
    for(int i=0;i<s.length();i++){
        set<int> st;
        for(int j = i;j<s.length();j++){
            st.insert(s[j]);
            if(st.size() <= k){
                maxlen = max(maxlen, j - i + 1);
            } else break;
        }
    }
    return maxlen;
}

int main(){
    string s = "aaabbbccd";
    int k = 2;
    cout<<longest_substr_Be(s, k)<<endl;
}