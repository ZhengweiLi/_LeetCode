/*
Given a 2d grid map of '1's (land) and '0's (water),
count the number of islands. An island is surrounded by water and is formed
 by connecting adjacent lands horizontally or vertically.
 You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n));
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == '0' || visited[i][j]) continue;
                helper(grid, visited, i, j);
                res++;
            }
        }
        return res;
    }
    void helper(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j]) return;
        visited[i][j] = true;

        helper(grid, visited, i - 1, j);
        helper(grid, visited, i + 1, j);
        helper(grid, visited, i, j - 1);
        helper(grid, visited, i, j + 1);
    }
};
