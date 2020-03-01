/*
Given two words word1 and word2,
find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/
//solution 1:recursively,but time limit exceeded.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> memo(m, vector<int>(n));
        return helper(word1, 0, word2, 0, memo);
    }
    int helper(string& word1, int i, string& word2, int j, vector<vector<int>>& memo){
        if(i == word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size() - i;
        if(memo[i][j] > 0) return memo[i][j];
        int res = 0;

        if(word1[i] == word2[j]){
            return helper(word1, i+1, word2, j+1, memo);
        }
        else{
            int deleteCnt = helper(word1, i+1, word2, j, memo);
            int insertCnt = helper(word1, i, word2, j+1, memo);
            int replaceCnt = helper(word1, i+1, word2, j+1, memo);

            return res = min(deleteCnt, min(insertCnt, replaceCnt)) + 1;
        }
        return memo[i][j] = res;
    }
};
//solution 2: DP
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        for(int i = 0; i <= m; i++) dp[i][0] = i;
        for(int i = 0; i <= n; i++) dp[0][i] = i;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
