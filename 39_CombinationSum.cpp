/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        combinationSumDFS(candidates, target, 0, out, res);
        return res;
    }
    void combinationSumDFS(vector<int>& candidates, int target, int begin, vector<int>& out, vector<vector<int>>& res){
        if(target<0) return;
        if(target==0) {res.push_back(out); return ;}

        for(int i=begin; i<candidates.size(); i++){
            out.push_back(candidates[i]);
            combinationSumDFS(candidates, target-candidates[i], i, out, res);
            out.pop_back();
        }
    }
};
