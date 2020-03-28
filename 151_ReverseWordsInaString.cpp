/*
Given an input string, reverse the string word by word.
Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
*/
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int index = 0;
        reverse(s.begin(), s.end());

        for(int i = 0; i < n; i++){
            if(s[i] != ' '){
                if(index != 0) s[index++] = ' ';

                int j = i;
                while(j < n && s[j] != ' ') s[index++] = s[j++];
                reverse(s.begin() + index - (j - i), s.begin() + index);
                i = j;
            }
        }
        s.resize(index);
        return s;
    }
};
