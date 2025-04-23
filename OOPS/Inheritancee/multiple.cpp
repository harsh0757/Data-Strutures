#include<iostream>
using namespace std;

class car{
public:
    void drive(){
        cout<<"Driving the car!"<<endl;
    }
};

class plane{
public:
    void fly(){
        cout<<"Flying the plane!"<<endl;
    }
};

class flyingCar : public car, public plane{
public: 
    void land(){
        cout<<"Landing the flying car "<<endl;
    }
};

int main(){
    flyingCar MyflyingCar;
    MyflyingCar.drive();
    MyflyingCar.fly();
    MyflyingCar.land();
}