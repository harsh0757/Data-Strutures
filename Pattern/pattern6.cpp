#include <bits/stdc++.h>
using namespace std;
// 12345
// 1234
// 123
// 12
// 1
////Link code studio --> https://bit.ly/3i06XDu

void print(int n)
{
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n-i+1;j++){
            cout<<j;
        }
        cout<<endl;
    }
}

int main()
{
    int t;
    cout << "Enter the number of Test cases : " << endl;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cout << "Enter for " << i << "th test case " << endl;
        cin >> n;
        print(n);
    }
}