#include<iostream>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);

    cout<<"Enter the array elements : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //pre-compute
    int hash[13] = {0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    cout<<"Enter the number of queries : "<<endl;
    int q;
    cin>>q;
    while(q--){
        int number;
        cout<<"Enter the number to count the frequencies : "<<endl;
        cin>>number;

        //fetch
        cout<<number<<" is appearing "<<hash[number]<<" time"<<endl;
    }
}