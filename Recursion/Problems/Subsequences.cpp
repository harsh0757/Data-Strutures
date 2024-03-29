#include <bits/stdc++.h>
using namespace std;

void subsequence(int idx, vector<int> &ds, int arr[], int n)
{
    if (idx == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    // not pick , or not take condition, this element is not added to your subsequence
    // subsequence(idx + 1, ds, arr, n);
    // take or pick the particular index into the subsequence
    ds.push_back(arr[idx]);
    subsequence(idx + 1, ds, arr, n);
    ds.pop_back();
    // not pick , or not take condition, this element is not added to your subsequence
    subsequence(idx + 1, ds, arr, n);
}

int main()
{
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    subsequence(0, ds, arr, n);
}