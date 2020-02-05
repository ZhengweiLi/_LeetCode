/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
    bool helper(vector<vector<char>>& board,int i,int j){
        if(i==9) return true;
        if(j>=9) return helper(board,i+1,0);
        if(board[i][j]!='.') return helper(board,i,j+1);

        for(char c='1';c<='9';c++){
            if(!isValid(board,i,j,c)) continue;
            board[i][j]=c;
            if(helper(board,i,j+1)) return true;
            else board[i][j]='.';
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board,int i,int j,char val){
        for(int x=0;x<9;x++){
            if(board[x][j]==val) return false;
        }
        for(int y=0;y<9;y++){
            if(board[i][y]==val) return false;
        }

        int row=i-i%3;
        int col=j-j%3;
        for(int m=0;m<3;m++){
            for(int n=0;n<3;n++){
                if(board[m+row][n+col]==val) return false;
            }
        }
        return true;
    }
};
