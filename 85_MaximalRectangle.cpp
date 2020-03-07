/*
Given a 2D binary matrix filled with 0's and 1's,
find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        vector<int> heights;

        for(int i = 0; i < matrix.size(); i++){
            heights.resize(matrix[0].size());

            for(int j = 0; j < matrix[0].size(); j++){
                heights[j] = matrix[i][j] == '0'? 0 : heights[j] + 1;

            }
            res = max(res, longestRectangleArea(heights));
        }
        return res;
    }
    int longestRectangleArea(vector<int>& heights){
        int res = 0;
        stack<int> st;
        heights.push_back(0);

        for(int i = 0; i < heights.size(); i++){
            if(st.empty() || heights[st.top()] <= heights[i]) st.push(i);
            else{
                int cur = st.top(); st.pop();
                res = max(res, heights[cur] * (st.empty()? i : i-st.top()-1));
                --i;
            }
        }
        return res;
    }
};
