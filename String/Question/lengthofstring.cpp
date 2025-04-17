#include<iostream>
using namespace std;

int getLength(char arr[]){
    int count = 0;
    for(int i=0;arr[i] != '\0'; i++){
        count++;
    }
    return count;
}

int main(){
    // string s = "Harsh";
    // int size = s.size();

    // cout<<"Length of the string is : "<<size<<endl;

    char name[20];
    cin>>name;
    
    cout<<"Length of the string is : "<<getLength(name)<<endl;
}