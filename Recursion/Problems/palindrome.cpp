#include <bits/stdc++.h>
using namespace std;

int palindorme(int num, int rev)
{
    if (num == 0)
    {
        return rev;
    }

    rev = (rev * 10) + (num % 10); // gives reverse
    return palindorme(num / 10, rev);
}

int main()
{
    int num;
    int rev;
    cout << "Enter a number : " << endl;
    cin >> num;
    rev = palindorme(num, 0);

    if (rev == num)
    {
        cout << "Yes it's a palindrome" << endl;
    }
    else
    {
        cout << "No, it's not a palindrome" << endl;
    }
}