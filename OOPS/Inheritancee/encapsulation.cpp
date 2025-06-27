#include<iostream>
using namespace std;

class Animal{
public:
    void sound(){
        cout<<"Animal makes Sound"<<" ";
    }
};

class dog : public Animal{
public:
    void sound(){
        cout<<"Dog Barks"<<endl;
    }
};

class BankAccount{
public:
    double balance;
    string owner;
public:
    BankAccount(string name, double initialBalance){
        owner = name;
        balance = initialBalance;
    }

    void deposit(int amount){
        if(amount > 0){
            balance = balance + amount;
        }
    }

    void widthraw(double amount){
        if(amount > 0 && amount <= balance){
            balance = balance  - amount;
        } else {
            cout<<"Insufficient Funds"<<endl;
        }
    }

    double getBalance(){
        return balance;
    }

    string getonwer(){
        return owner;
    }

};

int main(){
    BankAccount b("Harsh", 1000);
    b.deposit(500);
    b.widthraw(300);

    cout<<b.getBalance()<<endl;
    cout<<b.getonwer()<<endl;

    Animal* a = new dog();
    a->sound();

}