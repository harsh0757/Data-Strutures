#include <bits/stdc++.h>
using namespace std;
/*
Take the day no and print the coreesponding days
for 1 print Monday
for 2 print Tuseday and so on for 7 days print sunday.
*/
int main()
{
    int num;
    cout << "Enter number : " << endl;
    cin >> num;

    switch (num)
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thruday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "saturday" << endl;
        break;
    case 7:
        cout << "Sunday" << endl;
        break;
    default:
        cout << "Please enter a valid Week number" << endl;
    }
}