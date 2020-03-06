/*
Given a sorted array nums, remove the duplicates in-place
such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array,
you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5,
with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = 0, cur = 1;
        int cnt = 1, n = nums.size();

        while(cur < n){
            if(nums[pre] == nums[cur] && cnt == 0) ++cur;

            else{
                if(nums[pre] == nums[cur]) --cnt;
                else cnt = 1;
                nums[++pre] = nums[cur++];
            }
        }
        return nums.empty()? 0 : pre+1;
    }
};
