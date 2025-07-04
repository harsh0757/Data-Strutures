#include<iostream>
using namespace std;

//declartion

// const int *p  -->  pointer to constant int (you cannit modify the value pointed to)
// int* const p  -->  constant pointer to int (you cannot change the pointer itself)
// const int* const p  --> constant pointer to constant int (neither value nor address is mutable)

int main(){
    int a = 10, b = 20;

    const int *p1 = &a;      //value is constant
    // *p1 = 15             //cannot modify the value
    p1 = &b;


    int *const p2 = &a;      //pointer is constant
    *p2 = 30;                //allowed : modifying value   
    //  p2 = &b;             //Error : cannot change the address
    
    const int* const p3 = &a;  //both are consant
    //p3 = 30       //ERROR
    //p3 = &b       //ERROR
}