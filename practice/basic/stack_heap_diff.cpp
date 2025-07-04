#include<iostream>
using namespace std;

void stackExample(){
    int a = 5;  //stored in stack
    cout<<"Stack variable : "<<a<<endl;
}

void heapExample(){
    int *p = new int;   //allocated on heap
    if(p){
        *p = 10;
        cout<<"Heap variable : "<<*p<<endl;
        delete p;
    }
}

int main(){
    stackExample();
    heapExample();
    return 0;
}