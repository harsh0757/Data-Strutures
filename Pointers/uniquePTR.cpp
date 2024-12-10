//Excuslive ownership of the object
#include<iostream>
using namespace std;

//implementation
template <typename T>
class uniqueptr{
private:
    T* res;

public:
    uniqueptr(T* a = nullptr): res(a){
        cout<<"Inside Constructor"<<endl;
    }
    //compilation error for copy constructor
    uniqueptr(const uniqueptr<T>& ptr) = delete;
    uniqueptr& operator=uniqueptr(const uniqueptr<T>& ptr);
// R-value Reference (Type Context):
// When used in declarations or type contexts, && denotes an R-value reference.
// R-value references are references that can bind to temporary objects (R-values), 
// enabling efficient transfer of resources (e.g., in move semantics).
    uniqueptr(const uniqueptr<T>&& ptr){
        //transferred the ownership
        res = res.ptr;
        ptr.res = nullptr;
    }

    uniqueptr& operator=
};

int main(){
    uniqueptr<int> ptr1(new int(2));
    // uniqueptr<int> ptr2(ptr1); //compilation error
    // uniqueptr<int> ptr3 = ptr1; //compilation error
    uniqueptr<int> ptr4(new int(500)); //compilation error
    // ptr4 = ptr3; //compilation error

    uniqueptr<int> ptr3 = std::move(ptr1);
    ptr4 = std::move(ptr3);

    ptr1.func();
    cout<<*ptr1<<endl;
    ptr1.get();
    ptr1.reset(new int(30));

    //destructor --> to free up the resource

    return 0;
}