#include <iostream>
using namespace std;

template <typename T>

class MyVector{
    T* data;

    size_t _size;
    size_t _capacity;

    void resize(size_t newCapacity){
        T* newData = new T[newCapacity];

        for(size_t i = 0;i<_size;i++){
            newData[i] = data[i]; //copy elements
        }
        delete[] data;
        data = newData;
        _capacity = newCapacity;
    }
public:
    MyVector() : data(nullptr), _size(0), _capacity(0) {}

    ~MyVector(){
        delete[] data;
    }

    void push_back(const T& values){
        
    }
};

int main(){

}