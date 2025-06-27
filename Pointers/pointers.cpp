#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
//1.Basic pointer
    int x = 10;
    int *p = &x;
    cout<<*p<<endl;

    char ch = 'A';
    char *ptr = &ch;
    cout<<*ptr<<endl;

//2. NULL pointer
    int *ptr1 = nullptr;
    if(ptr1 == nullptr){
        cout<<"Null operation \n";
    }

//3. Dangling pointer
    int *ptr2 = new int(10);
    delete ptr2;
    cout<<*ptr2<<endl;

//4. Wild Pointer
    // int *ptr3; //should be initialised to resolve this error
    // *ptr3 = 10;
    // cout<<*ptr3<<endl;

//5.void pointer
    void* ptr4;
    int y = 10;
    ptr4 = &y;
    cout<<*(int*)ptr4<<endl;

//6.pointer to pointer
    int val = 5;
    int *pp = &val;
    int **ppp = &pp;
    cout<<**ppp<<endl;

}
