/*
Given a string s1, we may represent it as a binary tree
 by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
Input: s1 = "great", s2 = "rgeat"
Output: true
*/
//solution 1:recursion algorithm
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;

        string str1 = s1;
        string str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        if(str1 != str2) return false;
        for(int i = 1; i < s1.size(); i++){

            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if(isScramble(s11, s21) && isScramble(s12, s22)) return true;

            s21 = s2.substr(0, s1.size()-i);
            s22 = s2.substr(s1.size()-i);
            if(isScramble(s11, s22) && isScramble(s12, s21)) return true;
        }
        return false;
    }
};
//solution 2:dynamic programming method
1.subprob. dp[i][j][len]:s1从i开始，s2从j开始长度为len的字符串是否为Scramble
2.dp[i][j][len] = true: len个元素，len-1种划分方法，只要有一种划分方法满足条件赋值为真，每种划分下都涉及到swap左右子节点的可能
  dp[i][j][k] && dp[i+k][j+k][len-k] k= 1,...,len-1 该划分下s1、s2前k个元素和后len-k个元素比较，同时满足才能复值ture
  dp[i][j+len-k][k] && dp[i+k][j][len-k] k= 1,...,len-1 该划分下s1的前k个元素和s2的后k个元素比较，剩下部分比较
3.orig.prob. dp[0][0][n]
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;

        int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n+1)));

        for(int len = 1; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                for(int j = 0; j <= n - len; j++){

                    if(len == 1){
                        dp[i][j][len] = s1[i] == s2[j];
                    }
                    else{
                        for(int k = 1; k < len; k++){

                            if((dp[i][j][k] && dp[i+k][j+k][len-k])||
                               (dp[i][j+len-k][k] && dp[i+k][j][len-k])){
                                dp[i][j][len] = true;
                            };

                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
