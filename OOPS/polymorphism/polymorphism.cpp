#include<iostream>
using namespace std;

class printer{
public:
    void show(int a){
        cout<<"Interger : "<<a<<endl;
    }

    void show(string s){
        cout<<"String : "<<s<<endl;
    }
};

class complex{
public:
    int real, img;

    complex(int r, int i) : real(r), img(i){}

    complex operator+(const complex& other){
        return complex(real + other.real, img + other.img);
    }

    void display() {
        cout << "Complex: " << real << " + " << img << "i" << endl;
    }
};

int main(){
    printer p;
    p.show(10);
    p.show("Hello");

    complex c1(3,4), c2(1,2);
    complex c3 = c1 + c2;

    c3.display();
}