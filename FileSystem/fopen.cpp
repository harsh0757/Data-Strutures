#include <iostream>
using namespace std;

int main(){
    FILE* fptr;
    
    //opening the file in read mode
    fptr = fopen("Example.txt", "r");
    //creating the file
    fptr = fopen("File.txt", "w");


    //checking the file is opened successfully
    if(fptr == NULL)
        cout<<"File is opened"<<endl;
    else
        cout<<"Decrypting the data"<<endl;
    return 0;
}