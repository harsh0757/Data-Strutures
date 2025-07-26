#include<iostream>
using namespace std;

class Shape{
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape{
public:
    void draw() override {
        cout<<"Drawing Circle"<<endl;
    }
};

class Square : public Shape{
public: 
    void draw() override{
        cout<<"Drawing Square"<<endl;
    }
};

//factory class
class ShapeFactory{
public: 
    static Shape* createShape(const string& type){
        if(type == "circle") return new Circle();
        else if(type == "square") return new Square();
        else return nullptr;
    }
};

int main(){
    Shape* s1 = ShapeFactory::createShape("circle");
    Shape* s2 = ShapeFactory::createShape("square");

    if(s1) s1->draw();
    if(s2) s2->draw();

    delete s1;
    delete s2;
}