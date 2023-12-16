// mathematical formula
// Total no. of col * row + col;
//  it will store in the the form of linear array
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // creation of 2D array
    int arr[3][3] = {0};
    int size = 3;

    //initialision
    int brr[3][3] = {
        {4,5,6}, {1,11,111}, {2,22,222}
    };

    // take input
    //row wise input
    cout << "Enter the elments : " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }
    // output
    cout << "Prinitng the array : " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
