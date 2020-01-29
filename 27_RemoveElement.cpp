/*
Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val) nums[res++]=nums[i];
        }
        return res;
    }
};
