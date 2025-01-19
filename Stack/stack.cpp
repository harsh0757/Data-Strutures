#include<iostream>
using namespace std;

class Stack {
    int size;
    int *arr;
    int top;
public:
    Stack(int size){
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    ~Stack(){
        delete[] arr;
    }

    void Push(int x){
        if(top == size - 1) {
            cout<<"Stack is full"<<endl;
            return;
        }
        top = top + 1;
        arr[top] = x;
    }
    void Top(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<arr[top]<<endl;
    }
    void pop(){
        if(top == -1){
            cout<<"No space in the stack"<<endl;
        }
        cout<<"Element removed : "<<arr[top]<<endl;
        top = top - 1;
    }
    void Size(){
        cout<<"Size of stack is : "<<top + 1<<endl;
    }
};

int main(){
    Stack st(4);
    st.Push(5);
    st.Push(6);
    st.Push(7);
    st.Push(8);
    st.Push(9);
    st.Push(10);
    st.Top();
    st.pop();
    st.Top();
    st.Size();
    return 0;
}