#include <iostream>
using namespace std;

//Q1 struct vs class
struct MyStruct{
    int x;  //public by default
    void show(){
        cout<<x<<endl;
    }
};

class MyClass{
    int x;  //private by default
public:
    void set(int val){
        x = val;
    }
    void show(){
        cout<<x<<endl;
    }
};

