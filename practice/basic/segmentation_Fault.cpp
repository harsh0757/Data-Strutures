#include <iostream>
#include<memory>
using namespace std;

int main(){
    // 1.Invalid that cause segmentation fault
    int *ptr = NULL;
    // *ptr = 10;  //cause runtime crash: dereferencing null pointer

    //how to make safe
    //Example 1 : Using dynamic allocation
    int *ptr1 = new int;    //allocate memory
    *ptr1 = 10;             //safe
    cout << "Value: " << *ptr1 << endl;
    delete ptr1;

    //Example 2 : pointing to valid variable
    int value = 0;
    int* ptr2 = &value;
    *ptr2 = 10;  //safe
    std::cout << "Value: " << *ptr2 << std::endl;

    //Example 3 : using smart pointers
    unique_ptr<int> ptr3 = make_unique<int>(10); //automatically managed memory
    std::cout << "Value: " << *ptr3 << std::endl;

    return 0;
}