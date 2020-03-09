/*
Given a collection of integers that might contain duplicates,
nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()) return {};

        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());

        int size = 1, last = nums[0];
        for(int i = 0; i < nums.size(); i++){

            if(last != nums[i]){
                last = nums[i];
                size = res.size();
            }

            int newSize = res.size();
            for(int j = newSize - size; j < newSize; j++){

                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};
