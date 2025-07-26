#include<iostream>
using namespace std;

class shallowCopy{
public:
    int* data;

    shallowCopy(int val){
        data = new int(val);
    }

    ~shallowCopy(){
        delete data;
    }
};

class deepCopy{
public: 
    int *data;

    deepCopy(int val){
        data = new int(val);
        cout<<"Constructor data : "<<*data<<endl;
    }

    //deep copy constructor
    deepCopy(const deepCopy& other){
        data = new int(*other.data);
        cout<<"Deep copy constructor"<<*data<<endl;
    }

    //deep copy assigment operator
    deepCopy& operator=(const deepCopy& other){
        if(this  != &other){
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
};

int main(){
    shallowCopy obj1 (10);
    shallowCopy obj2 = obj1;

    *obj2.data = 20;

    cout<<*obj1.data<<endl;
    cout<<*obj2.data<<endl;

    deepCopy obj3(100);
    deepCopy obj4 = obj3;

    *obj4.data = 200;
    cout<<*obj3.data<<endl;
    cout<<*obj4.data<<endl;


}