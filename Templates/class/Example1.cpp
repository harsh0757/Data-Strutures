//basic type
#include<iostream>
using namespace std;

template <typename T>

class Box{
    T value;
public: 
    Box(T val) : value(val) {}

    void show(){
        cout<<"Value : "<<value<<endl;
    }
};

int main(){
    Box<int> myBox(44);
    myBox.show();

    Box<string> myString("Hello template");
    myString.show();
}