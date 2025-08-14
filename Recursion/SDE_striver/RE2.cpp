#include<iostream>
using namespace std;

void print_N_to_1_back(int i){
    if(i<=0) return;
    cout<<i<<endl;
    print_N_to_1_back(i-1);
}

void print_1_to_N_back(int i){
    if(i<=0) return;
    print_1_to_N_back(i-1);
    cout<<i<<endl;
}

void print_N_to_1(int n, int i){
    if(i>n) return;
    print_N_to_1(n, i+1);
    cout<<i<<endl;
}

void print_1_to_N(int n, int i){
    if(i>n) return;
    cout<<i<<endl;
    print_1_to_N(n, i+1);
}

void printName(int n, int i){
    if(i>n) return;
    cout<<"Harsh"<<endl;
    printName(n, i+1);
}

int main(){
    int n;
    cin>>n;
    print_N_to_1_back(n);

    return 0;
}