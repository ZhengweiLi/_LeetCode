/*
Given an unsorted array of integers,
find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore its length is 4.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;

        for(auto num : nums){
            if(!s.count(num)) continue;
            s.erase(num);
            int left = num - 1, right = num + 1;

            while(s.count(left)) s.erase(left--);
            while(s.count(right)) s.erase(right++);
            res = max(res, right - left - 1);
        }
        return res;
    }
};
