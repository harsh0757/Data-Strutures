#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Harsh";
    int len = s.size();
    s[len - 1] = 'z';
    // cout<<len-1;
    cout << s[len - 1] << endl;
}