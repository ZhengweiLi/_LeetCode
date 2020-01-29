/*
Given a sorted array nums, remove the duplicates in-place
such that each element appear only once and return the new length.

Do not allocate extra space for another array, y
ou must do this by modifying the input array in-place with O(1) extra memory.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n=nums.size();
        int pre=0,cur=0;
        while(cur<n){

            if(nums[pre]==nums[cur]) cur++;
            else{
                nums[++pre]=nums[cur++];
            }
        }
        return pre+1;
    }
};
