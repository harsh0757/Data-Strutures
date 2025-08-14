#include<iostream>
using namespace std;
//summison of n numbers

int sum_of_n_numbers(int i, int n, int sum){
    if(i>n) return 0;
    return i + sum_of_n_numbers(i+1, n, sum + i);
}

// void sum_of_n_numbers(int i, int n, int sum){
//     if(i>n) {
//         cout<<"Sum : "<<sum<<endl;  
//         return;
//     }
//     sum_of_n_numbers(i+1, n, sum+i);
// }

int main(){
    int n;
    cin>>n;
    int ans = sum_of_n_numbers(1, n, 0);
    cout<<ans<<endl;
}