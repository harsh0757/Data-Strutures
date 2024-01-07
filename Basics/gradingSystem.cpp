#include <bits/stdc++.h>
using namespace std;
/*
A school has following rules for grading system
a.below 25 - F
b.25 to 44 - E
c.45 to 49 - D
d.50 to 59 - C
e.60 to 79 - B
f.80 to 100 - A
Ask user to enter the marks and print the corresponding grade
*/
int main()
{
    int marks;
    cout << "Enter your marks : " << endl;
    cin >> marks;
    if (marks >= 80 && marks <= 100)
    {
        cout << "You got grade 'A' " << endl;
    }
    else if (marks >= 60 && marks <= 79)
    {
        cout << "You got grade 'B' " << endl;
    }
    else if (marks >= 50 && marks <= 59)
    {
        cout << "You got grade 'C' " << endl;
    }
    else if (marks >= 45 && marks <= 49)
    {
        cout << "You got grade 'D' " << endl;
    }
    else if (marks >= 25 && marks <= 44)
    {
        cout << "You got grade 'E' " << endl;
    }
    else
    {
        cout << "You need to work harder" << endl;
    }
    return 0;
}