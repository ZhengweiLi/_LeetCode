/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time
(i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int n = prices.size();
        int release1 = 0, release2 = 0;

        for(int i = 0; i < n; i++){
            hold1 = max(hold1, -prices[i]);
            release1 = max(release1, hold1 + prices[i]);

            hold2 = max(hold2, release1 - prices[i]);
            release2 = max(release2, hold2 + prices[i]);
        }
        return max(release1, release2);
    }
};
