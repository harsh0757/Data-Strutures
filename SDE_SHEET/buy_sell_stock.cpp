#include<iostream>
using namespace std;

//if you are selling on ith day you buy on the minimum from 1st day -> (i-1) day
int buy_sell_stock(vector<int>& arr){
    int mini = arr[0], profit = 0;
    for(int i=0;i<arr.size();i++){
        int cost = arr[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, arr[i]);
    }
    return profit;
}

int main(){
    vector<int> arr = {7,1,5,3,6,4};
    cout<<buy_sell_stock(arr)<<endl;
}