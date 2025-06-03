#include<iostream>
#include <memory>
using namespace std;

int main(){
    unique_ptr<int> ptr = make_unique<int>(42);
    cout<<"unique_ptr value : "<< *ptr <<endl;

    // unique_ptr<int> ptr2 = ptr; //Error : can't copy
    unique_ptr<int> ptr2 = move(ptr); // ownership moved

    if(!ptr) cout << "ptr is now null after move.\n";
    cout<< "ptr2 now owns the value : "<<*ptr2<<endl;
}