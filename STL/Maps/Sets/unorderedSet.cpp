#include<iostream>
#include<unordered_set>

using namespace std;

void print(unordered_set<string>& s){
// 1st method
    for(auto it : s){
        cout<<it<<" ";
    }
    cout<<endl;
//2nd method
    // for(auto it = s.begin(); it != s.end(); it++){
    //     cout<<(*it)<<endl;
    // }
}

int main(){
//stores unique elements and in sorted order
    unordered_set<string> s;
    s.insert("abc"); // O(1)
    s.insert("zsdf");
    s.insert("bcd");
//two ways to access values
    auto it = s.find("abcd"); //will return the iterator of that element
    if(it != s.end()){
        cout<<(*it);
        // s.erase(it);  we can directly pass the values also
    }
    print(s);
}