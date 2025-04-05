#include<iostream>
#include<thread>
using namespace std;

//non-static memebers cannot be defined outside the class
class Singleton{
private:
    static Singleton* instance;
    static mutex mutexlock;
    Singleton(){};

public:
    static Singleton* getInstance(){
        lock_guard<mutex> lock(mutexlock);
        if(instance == nullptr){
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mutexlock;

void threadFunc(){
    Singleton* instance = Singleton::getInstance();
    cout<<"Thread singleton instance address : "<<instance<<endl;
}

int main(){
    thread t1(threadFunc);
    thread t2(threadFunc);

    t1.join();
    t2.join();
}