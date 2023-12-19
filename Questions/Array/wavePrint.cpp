#include <iostream>
using namespace std;

void wavePrint(int arr[][3], int size){
    for(int j=0;j<size;j++){
        if(j%2 == 0){
            //even index -> top to bottom
                for(int i=0;i<size;i++){
                cout<<arr[i][j]<<" ";
            }
        } else {
            //odd index -> bottom to top
            for(int i = size-1;i>=0;i--){
                cout<<arr[i][j]<<" ";
            }
        }
    }cout<<endl;
}

int main(int argc, char const *argv[])
{
    int arr[3][3] = {3,4,11,2,12,1,7,8,7};
    int size = 3;

    wavePrint(arr,size);
    return 0;
}
