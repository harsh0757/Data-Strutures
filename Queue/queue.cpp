#include<iostream>
using namespace std;

class Queue {
    int start, end, size;
    int *arr;
public:
    Queue(int size){
        start = -1;
        end = -1;
        size  = this->size;
        arr = new int[size];
    }
    ~Queue(){
        delete[] arr;
    }

    void push(int element){
        if(end == size){
            cout<<"Queue is Full"<<endl;
        } else {
            arr[end] = element;
            end++;
        }
    }

    void pop(){
        if(start == end){
            cout<<"No elements to pop"<<endl;
        } else {
            int ans = arr[start];
            arr[start] = -1;
            start++;
            if(start == end){
                start = end = -1;
            }
        }
    }
    void Top(){
        if(start == end){
            cout<<"Queue is empty"<<endl;
        }
        cout<<"Front element : "<<arr[start]<<endl;
    }
};

int  main(){
}