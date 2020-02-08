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
/*
对于字符串s,p，指针分别为i,j从0开始，前面都一一匹配成功，当p出现*时，指针跳过*，比较i和j+1后续的匹配。
若p又出现*，继续同样的操作，当出现不匹配时，i和j应该回到哪里继续匹配？正则表达式中是回到前一个*，让*匹配s中的一个，
然后继续匹配，不匹配接着让*匹配两个，若*都匹配完了还是不匹配，就回到上上个*处，进行同样的操作，所以正则表达式采用的是迭代算法。

对于这道题，出现上述情况后，只用回到上一个*处就可以了，不用回到再之前的*去处理。所以只要记录上一个指针位置就可以了。
详细原因见：https://blog.csdn.net/louiey/article/details/81146303
*/
