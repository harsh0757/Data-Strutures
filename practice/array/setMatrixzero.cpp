#include<iostream>
using namespace std;

void markRow(vector<vector<int>>& arr, int n, int m, int i){
    for(int j = 0;j<m;j++){
        if(arr[i][j] != 0){
            arr[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>>& arr, int n, int m, int j) {
    for(int i=0;i<n;i++){
        if(arr[i][j] != 0){
            arr[i][j] = -1;
        }
    }
}

vector<vector<int> > matrixToZero( vector<vector<int>>& arr, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                markRow(arr, n, m, i);
                markCol(arr, n, m, j);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
        }
    }

    return arr;
}

int main(){
    vector<vector<int>> matrix = {{1,1,1,1}, {1,0,0,1}, {1,1,0,1}, {1,1,1,1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = matrixToZero(matrix, n, m);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}