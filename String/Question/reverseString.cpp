#include<iostream>
using namespace std;

void print(char name[]){
    for(int i=0;name[i] != '\0';i++){
        cout<<name[i]<<" ";
    }
    cout<<endl;
}

int getLength(char arr[]){
    int count = 0;
    for(int i=0;arr[i] != '\0'; i++){
        count++;
    }
    return count;
}

void reverse(char name[], int n){
    int start = 0;
    int end = n - 1;

    while(start < end){
        swap(name[start++], name[end--]);
    }

}

int main(){
    // string s = "Harsh";
    // int size = s.size();

    // cout<<"Length of the string is : "<<size<<endl;

    char name[20];
    cin>>name;
    int n = getLength(name);
    cout<<"Length of the string is : "<<getLength(name)<<endl;
    reverse(name, n);
    // print(name);
}