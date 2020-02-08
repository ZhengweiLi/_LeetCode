/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, n = s.size(), m = p.size();
        int istar = -1, jstar = -1;
        while(i < n){

            if(j < m && (s[i] == p[j] || p[j] == '?')){
                i++;j++;
            }
            else if(j < m && p[j] == '*'){
                istar = i;
                jstar = j++;
            }
            else if(istar >= 0){
                i = istar++;
                j = jstar + 1;
            }
            else return false;
        }
        while(j < m && p[j] == '*') j++;
        return j == m;

    }
};
