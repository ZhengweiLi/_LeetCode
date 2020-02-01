/*
Given an array of integers nums sorted in ascending order,
find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx=search(nums,0,nums.size()-1,target);
        if(idx==-1) return {-1,-1};
        int left=idx,right=idx;

        while(left>0&&nums[left-1]==target) left--;
        while(right<nums.size()-1&&nums[right+1]==target) right++;
        return {left,right};
    }

     int search(vector<int>& nums,int left,int right,int target){
            if(left>right) return -1;
            int mid=left+(right-left)/2;

            if(nums[mid]==target) return mid;
            if(nums[mid]<target) return search(nums,mid+1,right,target);
            else return search(nums,left,mid-1,target);
    }
};
