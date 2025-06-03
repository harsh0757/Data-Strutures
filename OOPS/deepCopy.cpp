#include<iostream>
using namespace std;

class deepCopy{
public:
    int *data;

    deepCopy(int val){
        data = new int(val);
    }

    deepCopy(const deepCopy& other){
        data = new int(*other.data);
    }
};

int main(){
    deepCopy obj1(10);
    deepCopy obj2 = obj1;

    *obj2.data = 20;

    cout << "obj1 data: " << *obj1.data << endl; // Shows 10
    cout << "obj2 data: " << *obj2.data << endl; // Shows 20


}