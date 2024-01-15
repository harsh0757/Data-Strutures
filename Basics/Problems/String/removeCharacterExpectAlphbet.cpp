#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "Gee&&&&&$ksfor$geeks";
    string result = "";

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            result += str[i];
        }
    }
    cout << result << endl;
}