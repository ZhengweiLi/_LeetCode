/*
Given a m x n matrix, if an element is 0,
set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())return ;
        int m = matrix.size(), n = matrix[0].size();
        bool rowZero = false, colZero = false;

        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0) rowZero = true;
        }
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0) colZero = true;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(rowZero){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
        if(colZero){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
    }
};
