#include<iostream>
using namespace std;

class stack{
    public:
    int *arr, top, size;

    stack(int size){
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack OverFlow"<<endl;
        }
    }

    void pop(){
        if(top > -1){
            top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }

    int peek(){
        if(top>0 && top<size){
        return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){

    }
};


int main(){

}