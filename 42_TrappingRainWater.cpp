/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int mx = 0, n = height.size();
        vector<int> dp(n,0);

        for( int i = 0; i < n; i++){
            dp[i] = mx;
            mx = max(mx, height[i]);
        }
        mx = 0;
        for(int i = n-1; i >= 0; i--){
            dp[i] = min(dp[i], mx);
            mx = max(mx, height[i]);

            if(dp[i] > height[i]) res+= dp[i] - height[i];
        }
        return res;
    }
};
