#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;
/*
Take the age from the user and then decide accordingly
1.if age < 18 
    print -> not eligible for job
2.if age>=18,
    print -> eligible for job
3.if age >=55 and age <= 57
    print -> eligible for job but retirement soon
4.if age > 57
    print -> retirement time
*/
int main()
{
    int age;
    cout << "Enter your age : ";
    cin >> age;

    if (age < 18)
    {
        cout << "Not eleigible for job" << endl;
    }
    else if (age<=57)
    {
        cout << "Eligible for job" << endl;
        if(age>=55){
            cout<<", but retirement soon"<<endl;
        }
    }
    else
    {
        cout << "retirement time" << endl;
    }
    return 0;
}