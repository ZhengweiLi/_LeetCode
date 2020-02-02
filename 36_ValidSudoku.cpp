/*
Determine if a 9x9 Sudoku board is valid.
 Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<9;row++){
            unordered_set<char> seen;
            for(int col=0;col<9;col++){
                if(board[row][col]!='.'){
                    if(seen.find(board[row][col])!=seen.end()) return false;
                    else seen.insert(board[row][col]);
                }
            }
        }
        for(int col=0;col<9;col++){
            unordered_set<char> seen;
            for(int row=0;row<9;row++){
                if(board[row][col]!='.'){
                    if(seen.find(board[row][col])!=seen.end()) return false;
                    else seen.insert(board[row][col]);
                }
            }
        }
        int row,col;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                unordered_set<char> seen;
                for(int m=0;m<3;m++){
                    for(int n=0;n<3;n++){
                        row=3*i+m;
                        col=3*j+n;
                        if(board[row][col]!='.'){
                            if(seen.find(board[row][col])!=seen.end()) return false;
                            else seen.insert(board[row][col]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
