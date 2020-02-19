/*
Given a matrix of m x n elements (m rows, n columns),
 return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;

        int c = m > n? (n + 1)/2 : (m + 1)/2;
        int p = m, q = n;
        for(int i = 0; i < c; i++, p -= 2, q -= 2 ){

            for(int col = i; col <= i+q-1; col++)
                res.push_back(matrix[i][col]);
            for(int row = i+1; row <= i+p-1; row++ )
                res.push_back(matrix[row][i+q-1]);

            if(p == 1 || q == 1) return res;
            for(int col = i+q-2; col >= i; col--)
                res.push_back(matrix[i+p-1][col]);
            for(int row = i+p-2; row >= i+1; row--)
                res.push_back(matrix[row][i]);
        }
        return res;
    }
};
