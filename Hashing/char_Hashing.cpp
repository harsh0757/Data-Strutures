#include<iostream>
using namespace std;

int main(){
    string s;
    //map the characters in hash array with indexes
    //ch - 'a' --> we will get the corresponding index in hash array
    cin>>s;

    //pre-compute
    int hash[256] = {0};    //if doesn't state about the exclusivity of character we have to take 256
    for(int i=0;i<s.length();i++){
        hash[s[i]]++;
        //hash[s[i] - 'a']
    }

    cout<<"Enter the number of queries : "<<endl;
    int q;
    cin>>q;
    while(q--){
        cout<<"Enter the character to count the frequencies : "<<endl;
        char c;
        cin>>c;

        //fetching
        // cout<<number<<" is appearing "<<hash[number]<<" time"<<endl;
        cout<<c<<" is appearing "<<hash[c]<< " time"<<endl;
        // cout<<c<<" is appearing "<<hash[c - 'a']<< " time"<<endl;
    }

}