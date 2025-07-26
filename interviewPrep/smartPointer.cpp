#include<iostream>
#include <memory>
using namespace std;

void test_unique(){
    cout<<"unique pointer"<<endl;
    unique_ptr<int> ptr = make_unique<int>(10);
    cout<<*ptr<<endl;

    //copying not allowed
    unique_ptr<int> ptr1 = std::move(ptr); //ownership moved
}

void test_shared(){
    cout<<"shared pointer"<<endl;
    shared_ptr<int> ptr = make_shared<int>(10);
    shared_ptr<int> ptr2 = ptr; //both share ownership

    cout<<*ptr<<" "<<ptr2.use_count()<<endl;
}

int main(){
    test_unique();
    test_shared();
}