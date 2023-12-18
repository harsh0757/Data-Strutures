#include <iostream>
using namespace std;

void wavePrint(int arr[][3], int size){
    for(int j=0;j<size;j++){
        if(j&1){
            //odd index -> bottom to top
            for(int i = size-1;i>=0;i--){
                cout<<arr[i][j]<<" ";
            }
        } else {
            //0 or even index -> tp to bottom
            for(int i=0;i<size;i++){
                cout<<arr[i][j]<<" ";
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[3][3] = {3,4,11,2,12,1,7,8,7};
    int size = 3;

    wavePrint(arr,size);
    return 0;
}
