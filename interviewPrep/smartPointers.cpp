#include<iostream>
using namespace std;

template<typename T>
class uniquePointer{
private:
    T* ptr;
public: 
    uniquePointer(T* p = nullptr ){
        ptr = p;
    }

    //delete copy constructor and assingment
    uniquePointer(const uniquePointer&) = delete;
    uniquePointer& operator=(const& uniquePointer&) = delete;

    //move constructor
    uniquePointer(uniquePointer&& other){
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    //move assingment
    uniquePointer& operator=(uniquePointer&& other)
};
