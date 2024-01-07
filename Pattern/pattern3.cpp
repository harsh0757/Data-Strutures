#include <bits/stdc++.h>
using namespace std;
// 1
// 12
// 123
// 1234
// 12345
////Link code studio --> https://bit.ly/3CiWV74

void print(int n)
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
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