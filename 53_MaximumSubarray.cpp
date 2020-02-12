/*
Given an integer array nums, find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/
/*动态规划

于是我们把目光落到动态规划上面来，首先需要把这个问题分解成最优子问题来解。
最主要的思路就是将上面的45个组合进行分类，分解成数量较少的几个子问题。
在这里我们一共有9个数字，顺理成章的我们把组合分解成9个小组的组合。

第一个子组合是以第一个数字结尾的连续序列，也就是[-2]，最大值-2

第二个子组合是以第二个数字结尾的连续序列，也就是[-2,1], [1]，最大值1

第三个子组合是以第三个数字结尾的连续序列，也就是[-2,1,3], [1,3], [3]，最大值4

以此类推。。。

如果我们能够得到每一个子组合的最优解，也就是子序列的最大值，整体的最大值就可以通过比较这9个子组合的最大值来得到了。
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, res = INT_MIN;
        for(int i = 0; i < nums.size(); i++){

            curSum += nums[i];
            curSum = max(curSum, nums[i]);
            res = max(res, curSum);
        }
        return res;
    }
};
