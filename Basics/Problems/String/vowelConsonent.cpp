#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    cout << "Enter a character " << endl;
    cin >> ch;

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        cout << "Character is vowel" << endl;
    }
    else
    {
        cout << "Character is Consonant" << endl;
    }
}