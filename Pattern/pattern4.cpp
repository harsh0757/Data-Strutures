#include <bits/stdc++.h>
using namespace std;
// 1
// 22
// 333
// 4444
// 55555
////Link code studio --> https://bit.ly/3Gzv70S

void print(int n)
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
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