#include <bits/stdc++.h>
using namespace std;
// *
// * *
// * * *
// * * * *
// * * * * *
//Link code studio --> https://bit.ly/3VADLAt

void print(int n)
{
    for (int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*"<<" ";
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