/*
Given a 2D board containing 'X' and 'O' (the letter O),
 capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){

                if((i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1)
                   && board[i][j] == 'O')
                    solveDFS(board, i, j);
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
    void solveDFS(vector<vector<char>>& board, int i, int j){
        if(board[i][j] == 'O'){
            board[i][j] = '$';

            if(i > 0 && board[i - 1][j] == 'O')
                solveDFS(board, i - 1, j);
            if(i < board.size() - 1 && board[i + 1][j] == 'O')
                solveDFS(board, i + 1, j);
            if(j > 0 && board[i][j - 1] == 'O')
                solveDFS(board, i, j - 1);
            if(j < board[0].size() - 1 && board[i][j + 1] == 'O')
                solveDFS(board, i, j + 1);
        }
    }
};
