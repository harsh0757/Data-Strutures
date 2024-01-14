#include <bits/stdc++.h>
using namespace std;

bool stringPalindrome(int i, string str)
{
    if (i > str.size() / 2)
        return true;
    if (str[i] != str[str.size() - i - 1])
        return false;

    return stringPalindrome(i + 1, str);
}

int main()
{
    string str = "abcd";
    if (stringPalindrome(0, str))
    {
        cout << "String is a plaindrome" << endl;
    }
    else
    {
        cout << "No, String is not a palindrome" << endl;
    }
}