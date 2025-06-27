#include<iostream>
using namespace std;

template <typename T>
class MyVector{
    T* data;
    size_t size;
    size_t capacity;
public:
    MyVector() : data(new T[10]), capacity(10), size(0) {}

    void push_back(const T& val){
        if(size < capacity) data[size++] = val;
    }
};

int main(){
}