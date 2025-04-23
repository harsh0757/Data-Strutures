// Definition: Binding data and functions together; hiding implementation details.
// Analogy: ATM machine – you just press buttons, don’t need to know how it works inside.
#include<iostream>
using namespace std;

class BankAccount{
private:
    int balance;
public:
    BankAccount() : balance(0){}
    void deposit(int amount){
        if(amount > 0) balance += amount;
    }

    bool witdhraw(int amount){
        if(amount > balance){
            cout<<"Amount exceed the current balance"<<endl;
            return false;
        }
        balance -= amount;
        return true;
    }

    int getBalance(){
        return balance;
    }
};

int main(){
    BankAccount acc;
    acc.deposit(1000);
    cout<<"Balance : " << acc.getBalance()<<endl;
    acc.witdhraw(1200);
}