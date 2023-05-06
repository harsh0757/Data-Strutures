#include <iostream>
using namespace std;

int sumOfEvenNumbers(int N){
    int sum = 0;
    for(int i=0;i<=N;i+=2){
            sum+=i;
    }
    return sum;
}
int sumOfoddNumbers(int N){
    int sum = 0;
    for(int i=0;i<=N;i++){
        if(i%2 != 0)
            sum+=i;
    }
    return sum;
}

int sumOfNNumbers(int N){
    int sum = 0;
    for(int i=1;i<=N;i++){
        sum+=i;
    }
    return sum;
}

int main(){
    int N,sum = 0;
    cin>>N;
    cout<<"Sum of N numbers : "<<sumOfNNumbers(N)<<endl;
    cout<<"Sum of N Even numbers : "<<sumOfEvenNumbers(N)<<endl;
    cout<<"Sum of N odd numbers : "<<sumOfoddNumbers(N)<<endl;
}