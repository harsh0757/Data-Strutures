#include<iostream>
using namespace std;

vector<vector<int>> rotateMatrix_OP(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return matrix;
}


//TC --> O(n2)  SC --> O(n2)
vector<vector<int>> rotateMatrix(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans(n,vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> ans = rotateMatrix_OP(arr);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}