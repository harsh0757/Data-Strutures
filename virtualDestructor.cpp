#include<iostream>
using namespace std;

class Base{
public:
    virtual ~Base(){
        cout<<"base destroyed\n";
    }
};

class Derived : public Base{
public:
    ~Derived(){
        cout<<"Derived Destroyed\n";
    };
};

int main(){
    Base* obj = new Derived();
    delete obj;
}