#include<iostream>
using namespace std;

void update(int arr[], int n){
    cout<<"Inside the function"<<endl;

    //updating the array
    arr[0] = 120;

    //printing the array
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    cout<<"Going Back to main"<<endl;
}

int main(){
    int arr[3] = {1,2,3};
    update(arr, 3);

    //printing the array
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}