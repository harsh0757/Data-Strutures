#include<iostream>
using namespace std;

class Vehicle{
public:
    void showDetails(){
        cout<<"This is a vehicle"<<endl;
    }
};

class car : virtual public Vehicle{
public:
    void drive(){
        cout<<"Driving the car!"<<endl;
    }
};

class plane : virtual public Vehicle{
public:
    void fly(){
        cout<<"Flying the plane!"<<endl;
    }
};

class flyingcar : public car, public plane{
public:
    void land(){
        cout<<"Landing the flying car!"<<endl;
    }
};

int main(){
    flyingcar myFlyingCar;
    myFlyingCar.showDetails();  // No ambiguity, only one Vehicle instance
    myFlyingCar.drive();
    myFlyingCar.fly();
    myFlyingCar.land();
}