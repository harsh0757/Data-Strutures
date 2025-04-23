#include<iostream>
using namespace std;

class Vehicle{
protected:
    int speed;
    int fuel;

public:
    Vehicle(int s, int f) : speed(s), fuel(f){}

    void display(){
        cout<<"Speed : "<<speed << "km/h, Fuel : "<<fuel << " liters"<<endl;
    }
    
    virtual void soundHorn() { //can be overridden by derived class
        cout<<"Vehicle horn sound!"<<endl;
    }
};

class car : public Vehicle{
private:
    int doors;
public:
    car(int s, int f, int d) : Vehicle(s, f), doors(d){}

    void display(){
        Vehicle::display();
        cout<<"Doors : "<<doors<<endl;
    }

    void soundHorn() override{
        cout<<"Car horn sound!"<<endl;
    }
};

int main(){
    car myCar(120, 50, 4);
    myCar.display();
    myCar.soundHorn();
    return 0;
}