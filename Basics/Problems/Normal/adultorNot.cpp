#include<bits/stdc++.h>
using namespace std;
//write a program that takes input of age
//and prints if you are adult or not
//>=18, yes
//<18, no
int main(){
    int age;
    cin>>age;

    if(age>=18){
        cout<<"You are an adult";
    }
    else if(age<=18){
        cout<<"Little kid go home";
    }
}