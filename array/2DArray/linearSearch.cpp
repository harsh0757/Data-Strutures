#include<iostream>
using namespace std;

bool isPresent(int arr[][3], int size, int target){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int arr[3][3] = {0};
    int size = 3;
    int target;

    cout << "Enter the elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout<<"Enter the target Element : "<<endl;
    cin>>target;

    if(isPresent(arr,size,target)){
        cout<<"Element is Present "<<endl;
    } else {
        cout<<"Element is not Present "<<endl;
    }


    return 0;
}
