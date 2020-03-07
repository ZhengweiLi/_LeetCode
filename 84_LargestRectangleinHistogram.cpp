/*
Given n non-negative integers representing the histogram's bar height
 where the width of each bar is 1,
 find the area of largest rectangle in the histogram.
 Input: [2,1,5,6,2,3]
Output: 10
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        for(int i = 0; i < heights.size(); i++){

            if(i+1 < heights.size() && heights[i] <= heights[i+1]){
                continue;
            }
            int minH = heights[i];
            for(int j = i; j >= 0; j--){

                minH = min(minH, heights[j]);
                res = max(res, minH*(i-j+1));
            }
        }
        return res;
    }
};
