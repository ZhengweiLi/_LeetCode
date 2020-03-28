/*
Suppose an array sorted in ascending order
 is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    int helper(vector<int>& nums, int begin, int end){
        if(begin == end) return nums[begin];
        if(nums[begin] < nums[end]) return nums[begin];

        int mid = (begin + end) / 2;
        return min(helper(nums, begin, mid), helper(nums, mid + 1, end));
    }
};
