#include <iostream>
using namespace std;

void shallowCopy(){
    int arr1[3] = {1,2,3};
    int *arr2 = arr1;  //shallow copy : just copies the address

    arr2[0] = 99;

    cout << "arr1[0]: " << arr1[0] << endl;
    cout << "arr2[0]: " << arr2[0] << endl;
}

void deepCopy(){
    int arr1[3] = {1,2,3};
    int arr2[3];

    // deep copy : copy values one by one
    for(int i=0;i<3;i++){
        arr2[i] = arr1[i];
    }

    arr2[0] = 99;

    cout << "arr1[0]: " << arr1[0] << endl;
    cout << "arr2[0]: " << arr2[0] << endl;
}

int main(){
    deepCopy();
}