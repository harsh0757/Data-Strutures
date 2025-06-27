#include<iostream>
using namespace std;

class MyClass{
public:
    int* data;
    MyClass(int val){
        data = new int(val);
    }

    MyClass(const MyClass& other){
        data = new int(*other.data);
    }

    ~MyClass(){
        delete data;
    }
};

int main(){
}