#include <bits/stdc++.h>
using namespace std;

//pass by value
void doSomething(int num)
{
    cout << "This is pass by value" << endl;
    cout << num << endl;
    num += 5;
    cout << num << endl;
    num += 5;
    cout << num << endl;
}
//pass by reference
void doSomething1(int &num)
{
    cout << "This is pass by refrence" << endl;
    cout << num << endl;
    num += 5;
    cout << num << endl;
    num += 5;
    cout << num << endl;
}
//array is always goes with reference
void print(int arr[], int size)
{
    for (int i = 0; i <= size - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // int num = 10;
    int arr[5] = {5, 10, 7, 12, 13};
    int size = 5;
    print(arr, size);
    return 0;
}