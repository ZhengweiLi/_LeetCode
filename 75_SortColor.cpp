/*
Given an array with n objects colored red, white or blue,
sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size()-1;
        for(int i = 0; i <= blue; i++){

            if(nums[i] == 0){
                swap(nums[i], nums[red++]);
            }
            else if(nums[i] == 2){
                swap(nums[i--], nums[blue--]);
            }

        }
    }
};
