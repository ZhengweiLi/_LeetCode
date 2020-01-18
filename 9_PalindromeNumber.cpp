/*Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int dev=1,left=0,right=0;
        while(x/dev>=10) dev*=10;
        while(x>0){
            left=x/dev;
            right=x%10;
            if(left!=right) return false;
            x=(x%dev)/10;
            dev/=100;

        }
        return true;
    }
};
