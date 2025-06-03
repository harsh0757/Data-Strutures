//multiple Types
#include<iostream>
using namespace std;

template <typename T1, typename T2>

void printSum(T1 a, T2 b){
    cout<<"Sum: "<< a + b<< endl;
}

int main(){
    printSum(3, 4.5);
    printSum(10, 20);

    return 0;
}