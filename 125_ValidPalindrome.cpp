/*
Given a string, determine if it is a palindrome,
considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem,
we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){

            while(left < right && !isAlphaNum(s[left])) left++;
            while(left < right && !isAlphaNum(s[right])) right--;
            if(tolower(s[left])!= tolower(s[right])) return false;
            else{
                left++;
                right--;
            }
        }
        return true;
    }
    bool isAlphaNum(char& s){
        if(s >= '0' && s <= '9') return true;
        if(s >= 'a' && s <= 'z') return true;
        if(s >= 'A' && s <= 'Z') return true;

        return false;

    }
};
