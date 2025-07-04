#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> setToZero_Op(vector<vector<int>>& matrix, int n, int m){
    // vector<int>row(n, 0); //row array
    // vector<int>col(m, 0); //col array

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    return matrix;
}

// TC --> O(2 * n * m)  SC --> O(n) + O(m)
vector<vector<int>> setToZero_be(vector<vector<int>>& matrix, int n, int m){
    vector<int>row(n, 0); //row array
    vector<int>col(m, 0); //col array

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

// TC --> O(n*m) * (n+m) + (n*m) nearly about n^3
void markRow(vector<vector<int>>& matrix, int n, int m, int i){
    for(int j=0;j<m;j++){
        if(matrix[i][j] !=0){
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>>& matrix, int n, int m, int j){
    for(int i=0;i<n;i++){
        if(matrix[i][j] !=0){
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> setToZero(vector<vector<int>>& matrix, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> ans = setToZero_be(matrix, n, m);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}