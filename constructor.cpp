#include<iostream>
using namespace std;

class constructor{
    constructor(){
        cout<<"this is a constructor"<<endl;
    }
};

class paraConstructor{
    int x;
public: 
    paraConstructor(int val){
        x = val;
        cout<<"this is a paraConstructor"<<endl;
    }
};

// 1.used to create new object as a copy of an existing object
//2.Takes a const reference: A(const A& other)
//3. Invoked during
    // --> Passing object by value
    // -->returning object by value
    // -->initializing one object with another
class copyConstructor{
public: 
    int x;
    copyConstructor(int val) : x(val){}
    copyConstructor(const copyConstructor& other){
        cout<<"copyConstructor"<<endl;

        x = other.x;
    }  //refering to an const object
};

//1.Trnsfers ownership of resources from a temporary(rvalue) object
//2.prevent uncessary deep copies
//3.Syntax A(A&&other)
//4.use with std::move()

class moveConstructor{
public: 
    int *data;
    moveConstructor(int val){
        data = new int(val);
    }

    //move constructor
    moveConstructor(moveConstructor&& other){
        cout<<"moveConstructor"<<endl;
        data = other.data;
        other.data = nullptr;
    }
};

int main(){
    copyConstructor a1(10);
    copyConstructor a2 = a1;

    moveConstructor a3(99);
    moveConstructor a4 = std::move(a3);
}