#include<iostream>
#include<memory>
using namespace std;

int main(){
    shared_ptr<int> a = make_shared<int>(100);
    shared_ptr<int> b = a; //both have same objects

    cout<<"value from a : "<<*a<<endl;
    cout<<"value from b : "<<*b<<endl;
    cout<<"Referecne count : "<< a.use_count()<<endl;

    return 0;
}