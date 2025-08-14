#include<iostream>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n){
    int drow = row;
    int dcol = col;

    while(drow>=0 && dcol>=0){
        if(board[drow][dcol] == 'Q') return false;
        drow--;
        dcol--;
    }

    drow = row;
    dcol = col;
    while(dcol>=0){
        if(board[drow][dcol] == 'Q') return false;
        dcol--;
    }

    drow = row;
    dcol = col;
    while(drow<n && dcol>=0){
        if(board[drow][dcol] == 'Q') return false;
        drow++;
        dcol--;
    }
    return true;
}

void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n = 4;
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    solve(0, board, ans, n);

    cout << "Total Solutions: " << ans.size() << "\n\n";
    for (auto& solution : ans) {
        for (auto& row : solution) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}