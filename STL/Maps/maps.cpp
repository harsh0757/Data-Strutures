#include<iostream>
#include<map>
using namespace std;

int main(){
    //It will store any type of value
    map<int, string> m;
    m[1] = "abc";
    m[5] = "cdc";
    m[3] = "acd";

    m.insert({4, "afg"});

//long method
//here iterator is pointinf to pair
    map<int,string> :: iterator it;
    for(it = m.begin(); it!=m.end();it++){
        // cout<<(*it).first << " "<< (*it).second <<endl;
        cout<<it->first<< " "<<it->second<<endl;
    }
}