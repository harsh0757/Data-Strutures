    #include<iostream>
    using namespace std;

    vector<vector<int>> setToZero(vector<vector<int>> arr, int n, int m){
        vector<int> row (n, 0);
        vector<int> col (m, 0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i] || col[j]){
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
        vector<vector<int>> ans = setToZero(matrix, n, m);

        for(auto it : ans){
            for(auto j : it){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }