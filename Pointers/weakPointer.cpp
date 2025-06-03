#include<iostream>
#include<memory>

using namespace std;

int main(){
    shared_ptr<int> sp = make_shared<int>(55);
    weak_ptr<int> wp = sp; //weak pointer does not increase use_count

    cout<< "Reference count (after weak_ptr): " <<sp.use_count()<<endl;

    if(auto spt = wp.lock()){
        cout << "Accessing value via weak_ptr: " << *spt << endl;
    } else {
        cout << "Object already deleted.\n";
    }
    
    sp.reset(); //destroys the shared_ptr's managed objects

    if (auto spt = wp.lock()) {
        cout << "Still alive: " << *spt << endl;
    } else {
        cout << "After reset, object is gone.\n";
    }
}