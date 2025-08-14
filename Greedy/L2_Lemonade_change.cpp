#include <iostream>
using namespace std;

// TC --> O(n)
bool lemonade_change(vector<int> &bills) {
    // no significance of 20 because you are not going to retun 20 to anyone
    int five = 0, ten = 0;
    // int twenty = 0;
    for (int i = 0; i < bills.size(); i++) {
        if (bills[i] == 5){
            five++;
        }
        else if (bills[i] == 10) {
            if (five) {
                five = five - 1;
                ten = ten + 1;
            }
            else
                return false;
        }
        else {
            if(ten && five) {
                five -= 1;
                ten -= 1;
            } else if(five >= 3){
                five -= 3;
            } else return false;
        }
    }
    return true;
}

int main()
{
    // vector<int> bills = {5, 5, 5, 10, 20};
    vector<int> bills = {5,5,10,10,20};

    if(lemonade_change(bills)){
        cout<<"Can sell the lemonade"<<endl;
    } else {
        cout<<"Not enough change"<<endl;
    }
}