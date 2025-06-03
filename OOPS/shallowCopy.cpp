#include<iostream>
using namespace std;

class shallow{
public:
    int *data;

    shallow(int val){
        data = new int(val);
    }

    ~shallow(){
        delete data;
    }
};

int main(){
    shallow obj1(10);
    shallow obj2 = obj1;

    *obj2.data = 20;

    cout << "obj1 data: " << *obj1.data << endl; // Shows 20
    cout << "obj2 data: " << *obj2.data << endl; // Shows 20

    return 0;
}