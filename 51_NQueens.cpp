/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard
such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
both indicate a queen and an empty space respectively.

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> queens(n, string(n, '.'));
        helper(0, queens, res);
        return res;
    }
    void helper(int row, vector<string>& queens, vector<vector<string>>& res){
        int n = queens.size();
        if(row == n) {res.push_back(queens); return ;}

        for(int i = 0; i < n; i++){
            if(isValid(queens, row, i)){
                queens[row][i] = 'Q';
                helper(row+1, queens, res);
                queens[row][i] = '.';
            }
        }
    }
    bool isValid(vector<string>& queens, int row, int col){
        for(int i = 0; i < row; i++){
            if(queens[i][col] == 'Q') return false;
        }
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if(queens[i][j] == 'Q') return false;
        }
        for(int i = row-1, j = col+1; i >= 0 && j < queens.size(); i--, j++){
            if(queens[i][j] == 'Q') return false;
        }
        return true;
    }
};
