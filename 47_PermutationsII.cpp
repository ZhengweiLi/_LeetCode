/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out, visited(nums.size(), 0);

        sort(nums.begin(), nums.end());
        permuteUniqueDFS(nums, 0, visited, out, res);
        return res;
    }
    void permuteUniqueDFS(vector<int>& nums, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res){
        if(level == nums.size()) {res.push_back(out); return ;}
        for(int i = 0; i < nums.size(); i++){

            if(visited[i] == 1) continue;
            if(i > 0 && nums[i] == nums[i-1] && visited[i-1] == 0) continue;
            out.push_back(nums[i]);
            visited[i] = 1;

            permuteUniqueDFS(nums, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }

    }

};
