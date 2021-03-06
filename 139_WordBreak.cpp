/*
Given a non-empty string s and a dictionary wordDict
 containing a list of non-empty words,
  determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;

        for(int i = 0; i <dp.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && wordSet.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
