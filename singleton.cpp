#include<iostream>
using namespace std;

class Singleton{
private:
    static Singleton* instance;
    Singleton(){ }
public: 
    static Singleton* getInstance(){
        if(instance == nullptr){
            instance = new Singleton();
        }
        return instance;
    }
    void showMessage(){
        cout<<"Singleton instance address : "<<this<<endl;
    }
};

Singleton* Singleton::instance = nullptr;

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    if(s1 == s2){
        cout<<"Both are same"<<endl;
    } else {
        cout<<"Different"<<endl;
    }
    s1->showMessage();
    return 0;
}