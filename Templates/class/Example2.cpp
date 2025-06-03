//class template with specialization
#include<iostream>
using namespace std;

template <typename T>
class Printer{
public:
    void print(T val){
        cout << "Value: " << val << endl;
    }
};

//specialization for char*
template<>
class Printer<char*>{
public:
    void print(char* val){
        cout << "Char* string: " << val << endl;
    }
};

int main(){
    Printer<int> p1;
    p1.print(100);

    Printer<char*> p2;
    p2.print((char*)"Specialized Template!");
}