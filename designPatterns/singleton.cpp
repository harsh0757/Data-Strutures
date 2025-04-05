#include<iostream>
using namespace std;

class Singleton{
private:
    static Singleton* instance;
    Singleton(){}

public: 
    static Singleton* getInstance(){
        if(instance == nullptr){
            instance = new Singleton();
        }
        return instance;
    }

    void showmessage(){
        cout<<"singleton instance address : "<<this<<endl;
    }
};

Singleton* Singleton::instance = nullptr;

int main(){
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    s1->showmessage();
    s2->showmessage();
}