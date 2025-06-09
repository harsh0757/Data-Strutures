#include <iostream>
#include <map>
#include <set>
using namespace std;

//TC --> O(N) SC --> O(1)
int fruit_in_basket_Op(vector<int> &arr) {
    int l = 0, r = 0, maxlen = 0;
    // number, freq
    map<int, int> basket;
    while (r < arr.size()) {
        basket[arr[r]]++;
            if (basket.size() > 2) { 
                basket[arr[l]]--;
                if (basket[arr[l]] == 0) basket.erase(arr[l]);
                l++;
            }
        if(basket.size() <= 2)  maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

// TC --> O(N+N) SC -->O(3)
int fruit_in_basket_be(vector<int> &arr) {
    int l = 0, r = 0, maxlen = 0;
    // number, freq
    map<int, int> basket;
    while (r < arr.size()) {
        basket[arr[r]]++;
            while (basket.size() > 2) { 
                basket[arr[l]]--;
                if (basket[arr[l]] == 0) basket.erase(arr[l]);
                l++;
            }
        if(basket.size() <= 2)  maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}
// trim down to find the length of subarray with at most two types of numbers
//  TC-->O(N * N) for set LOG(3) can be ignored which is equal to 1 only. SC --> O(3)
int fruit_in_basket(vector<int> &arr) {
    int maxlen = 0;

    for (int i = 0; i < arr.size(); i++) {
        set<int> basket;
        for (int j = i; j < arr.size(); j++) {
            basket.insert(arr[j]);
            if (basket.size() <= 2) {
                maxlen = max(maxlen, j - i + 1);
            }
            else
                break;
        }
    }
    return maxlen;
}

int main()
{
    // arr is the tree and each is giving fruits of types mentioned as array nunmber
    vector<int> arr = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << "Max len with two tyes of number : " << fruit_in_basket_Op(arr) << endl;
}