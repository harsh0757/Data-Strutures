#include<iostream>
#include<set>

using namespace std;

void print(multiset<string>& s){
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
//allow us to store multiple values
    multiset<string> s;
    s.insert("abc"); // O(log(n))
    s.insert("zsdf");
    s.insert("bcd");
    s.insert("abc");
//two ways to access values
    auto it = s.find("abc"); //will return the iterator of that element
    if(it != s.end()){
        // cout<<(*it);
        s.erase(it);  //we can directly pass the values also
        // in this case particular iterator value it will delete
    }
    // s.erase("abc"); in this case it will delete all these related values
    print(s);
}