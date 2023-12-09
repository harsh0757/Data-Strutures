#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    cout<<"Priting the array"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    cout<<"printing done";
}

int main(){
    //declare
    int num[5];
    //accessing the array
   /* cout << "value at 0th index " << num[0]<<endl;
    cout << "value at 1 th index " << num[1]<<endl;
    cout << "value at 25th index " << num[25]<<endl; */

    //initialise an array
    int arr[5] = {1,2,3,4,5};

    //accessing an element
    cout << "value at 2 index " << arr[4]<<endl;

    int third[15] = {2,7};
    
    // initialising all locations with 0
    int forth[10] = {0};
    // initialising all locations with 1
    int fifth[10] = {1}; //not possible
    printArray(fifth, 10);
    int n = 15;
    //print the array
    for(int i=0;i<n;i++){
        cout<<third[i]<<" ";
    }
    cout<<endl;


    cout<<"everything is fine"<<endl;
}