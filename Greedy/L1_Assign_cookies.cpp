#include<iostream>
using namespace std;

//TC --> O(nlogn + mlogm + m)
int assign_cookies(vector<int>& greed, vector<int>& cookies){
    int n = greed.size();
    int m = cookies.size();

    sort(greed.begin(), greed.end());
    sort(cookies.begin(), cookies.end());

    int l = 0, r = 0;

    while(l<m && r<n){
        if(cookies[l] >= greed[r]){
            r = r + 1;
        }
        l = l + 1;
    }
    return r;
}

int main(){
    vector<int> greed = {1,5,3,3,4};
    vector<int> cookies = {4,2,1,2,1,3};

    cout<<assign_cookies(greed, cookies)<<endl;
}