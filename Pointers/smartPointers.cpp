#include<iostream>
using namespace std;

void func(){
    for(int i=0;i<10000000;i++){
        cout<<"hey"<<endl;
        int *a = new int(10);
        delete a;
    }
}

int main(){
    func();
} 