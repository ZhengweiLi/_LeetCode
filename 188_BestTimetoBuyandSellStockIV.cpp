/*
Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k >= n) k = n;

        vector<int> hold(k + 1,INT_MIN);
        vector<int> release(k + 1, INT_MIN);
        int res = INT_MIN;
        release[0] = 0;

        for(int i = 0; i < n; i++){
            for(int j = 1; j <= k; j++){

                hold[j] = max(hold[j], release[j - 1] - prices[i]);
                release[j] = max(release[j], hold[j] + prices[i]);
            }
        }

        for(int val : release){
            res = max(res, val);
        }
        return res;
    }
};
