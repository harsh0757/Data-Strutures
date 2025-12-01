#include<iostream>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char c){
    for(int i=0;i<9;i++){
        if(board[i][col] == c){

        }
    }
}

bool sudokuSolver(vector<vector<char>> board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();i++){
            if(board[i][j] == '.'){
                for(char c = '1';c<='9';c++){
                    if(isValid(board, i, j, c)){
                        board[i][j] = c;
                        if(sudokuSolver(board) == true) return true;
                        else board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},

        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},

        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "Sudoku Grid:\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    sudokuSolver(board);

    return 0;
}

/*
Sudoku solver --> 9*9
1.Each digit 1 to 9 should appers once in any given row
2.Each digit 1 to 9 should appers once in any given col
3.Each digit 1 to 9 should appers once in any given 3*3 board
*/