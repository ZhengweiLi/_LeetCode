/*
Given a positive integer n, generate a square matrix filled with elements
from 1 to n^2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int c = n/2, p = n;
        int val = 1;

        for(int i = 0; i < c; p-=2, i++){
            for(int col = i; col < i+p; col++)
                res[i][col] = val++;
            for(int row = i+1; row < i+p; row++)
                res[row][i+p-1] = val++;
            for(int col = i+p-2; col >= i; col--)
                res[i+p-1][col] = val++;
            for(int row = i+p-2; row > i; row--)
                res[row][i] = val++;
        }
        if(n%2 != 0) res[n/2][n/2] = val;
        return res;
    }
};
