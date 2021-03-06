/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word
(last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/
//字符串字面值：有双引号""构成，" ",代表一个字符数组，是由字符' '和'\0'构成
//字面值：由单括号''构成。' '是字符' '
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++){

            if(s[i] != ' '){
                if(i != 0 && s[i-1] == ' ') res = 1;
                else res++;
            }
        }
        return res;
    }
};
