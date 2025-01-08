#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {2,3,5,6,7};
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
//declartion of iteator
    vector<int> ::iterator it = v.begin();
//how to get the values
    cout<<(*(it+1))<<endl;
//loop
    for(it = v.begin(); it!=v.end();it++){
        cout<<(*it)<<endl;
    }
//iterators point to pairs
    vector<pair<int, int>> v_p = {{1,2}, {2,3}, {3,4}};
    vector<pair<int, int>> ::iterator it1 = v_p.begin();
    for(it1 = v_p.begin(); it1 != v_p.end(); it1++){
        // cout << (*it1).first <<" " << (*it1).second << endl;  //it pointing to pair
        cout << it1->first <<" " << it1->second << endl;
    }
}