#include<iostream>
using namespace std;

template<typename T>

//function template
T add(T a, T b){
    return a+b;
}

// class template
template<typename T>
class Box{
    T value;
public:
    void set(T val){
        value = val;
    }

    T get() return value;
};

int main(){
    cout<<add(4, 5)<<endl;
}