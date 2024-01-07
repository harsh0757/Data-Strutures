#include <bits/stdc++.h>
using namespace std;
//Functions are set of code which performs something for you
//Functions are used to modularise code
//Functions are to increase readability
//Functions are used to use same code multiple times
//1.void --> Which does not return anything
// 2.return -->
// 3.parameters -->
// 4.non parameterised -->

void printName()
{ // non parameterised, void
    cout << "Hey Harsh!" << endl;
}
void printName(string name)
{ //parameterised function
    cout << "Hey " << name << endl;
}

//take two numbers and print its sum
int sum(int num1, int num2)
{
    int sum = num1 + num2;
    return sum;
}
int max(int num1, int num2)
{
    if (num1 >= num2)
        return num1;
    else
        return num2;
}

int main()
{
    int num1, num2;
    cout << "Enter two Numbers : " << endl;
    cin >> num1 >> num2;
    int minimum = min(num1, num2);
    cout << "The minimum number is : " << minimum << endl;
    int maximum = max(num1, num2);
    cout << "The maximum number is : " << maximum << endl;
    cout << "Sum of two numbers : " << sum(num1, num2) << endl;
    return 0;
}