/*Example 1:
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0,left=-1;
        unordered_map<int,int> m;
        for(int i=0;i<s.size();i++){
            if(m.count(s[i])&&m[s[i]]>left){
                left=m[s[i]];
            }
            m[s[i]]=i;
            res=max(res,i-left);
        }
        return res;
    }
};
