#include<iostream>
#include<map>
using namespace std;

void print(map<int, string> &m){
    cout<<m.size()<<endl;
//n(log(n))
    for(auto &it : m){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
}

int main(){
    map<int, string> mpp;
    map<string, string> m;
//uses red black tree or self balancing tree
    mpp[1] = "abc"; //O(log(n))
    mpp[5] = "cdc";
    mpp[3] = "acd";
    mpp[5] = "def";
    mpp[6];
    m["abcd"] = "abcd"; // s.size() * log(n)

//We cannot insert duplicate value in map it we add it then it will be replaced with the same value

    mpp.insert({4, "afg"});
    mpp.clear();

    auto it = mpp.find(7);
    if(it != mpp.end()) mpp.erase(it); // log(n)
    if(it == mpp.end()){
        cout<<"No value";
    } else {
        cout<<it->first<<" "<<it->second<<endl;
    }
    print(mpp);


// if we do like below by default it will assign the empty string or if the pair is of int datatype it will assign it to zero
// This will return iterator

//we can either give the value fo iterator or can give the key
//for saftey check that it will not pointing to end and not through segmentation fault
    

//maps stores data in sorted order
//old method
    // map<int, string> :: iterator it;
    // for(it = m.begin(); it != m.end(); it++){
    //     cout<<it->first << " " << it->second << endl;
    // }
    // cout<<endl;
}