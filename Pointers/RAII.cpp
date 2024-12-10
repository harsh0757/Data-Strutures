#include<iostream>
//RAI --> Resource Acquisition in initialisation
using namespace std;

class Wrapper{
    private:
    int *mem;
    public:
        Wrapper(int *a) : mem(a){
            cout<<"Inside constructor"<<endl;
        }
        ~Wrapper(){
            cout<<"Inside destructor"<<endl;
            delete mem;
        }
};

int main(){
    // int *a = new int(10); // raw pointer
    Wrapper obj(new int(10));
    return 0;
}
