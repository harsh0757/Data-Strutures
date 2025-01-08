//why needed pair
//to mainatin the relation
#include<iostream>
using namespace std;

int main(){
//pair<1,2> here 1 and 2 are data types
    pair<int, string> p;
//how to add value by internal fucntion
    // p = make_pair(2, "abc");
//easy way to initialize
    p = {2, "abcd"};
    pair<int, string>& p1 = p;
    p1.first = 3;
    cout<<p.first<<" "<<p.second<<endl;

    pair<int, int> p_array[3];
    p_array[0] = {1,2};
    p_array[1] = {2,3};
    p_array[2] = {3,4};

    for(int i=0;i<3;i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }
}