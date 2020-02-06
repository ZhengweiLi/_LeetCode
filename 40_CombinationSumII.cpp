/*
Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;

        sort(candidates.begin(), candidates.end());
        combinationSumDFS(candidates, 0, target, out, res);
        return res;


    }
     void combinationSumDFS(vector<int>& candidates,
                            int begin, int target,
                            vector<int>& out,
                            vector<vector<int>>& res){

         if (target < 0) return ;
         if (target == 0) {res.push_back(out); return ;}
         for (int i = begin; i < candidates.size(); i++){

             if(i > begin && candidates[i] == candidates[i-1]) continue;
             out.push_back(candidates[i]);
             combinationSumDFS(candidates, i+1, target - candidates[i], out, res);
             out.pop_back();
            }
        }
};
