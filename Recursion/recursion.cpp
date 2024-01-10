#include<bits/stdc++.h>
using namespace std;
//infinite recursion
//stack overflow problem will come
int cnt = 0;
void print(){
    if(cnt == 4) { 
        return;
    }
    cout<<cnt<<endl;
    cnt++;
    print();
}

int main(){
    print();
    return 0;
}