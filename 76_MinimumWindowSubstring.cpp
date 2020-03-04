/*
Given a string S and a string T,
find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> letterCnt;
        int left = 0, cnt = 0, minLen = INT_MAX;
        string res;

        for(char letter : t) ++letterCnt[letter];

        for(int i = 0; i < s.size(); i++){
            if(--letterCnt[s[i]] >= 0) ++cnt;

            while(cnt == t.size()){

                if(minLen > i-left+1){
                    minLen = i-left+1;
                    res = s.substr(left, minLen);
                }

                if(++letterCnt[s[left]] > 0) --cnt;
                left++;
            }
        }
        return res;
    }
};
