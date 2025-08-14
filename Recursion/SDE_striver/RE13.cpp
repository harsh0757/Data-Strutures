#include <iostream>
using namespace std;

void print_all_permutation(vector<int> &arr, vector<int> &ls, vector<vector<int>> &ans, int index){
    if (index == arr.size()){
        ans.push_back(arr);
        return;
    }
    for (int i = index; i < arr.size(); i++){
        swap(arr[index], arr[i]);
        print_all_permutation(arr, ls, ans, index + 1);
        swap(arr[index], arr[i]);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> ls;

    print_all_permutation(arr, ls, ans, 0);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}