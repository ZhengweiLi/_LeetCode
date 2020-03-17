/*
Given a string S and a string T,
count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string
by deleting some (can be none) of the characters without disturbing the relative positions
 of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<long>> dp(m + 1, vector<long>(n + 1));

        for(int i = 0; i <= m; i++) dp[i][0] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){

                dp[i][j] = dp[i - 1][j] + (s[i - 1] == t[j - 1]? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[m][n];
    }
};
