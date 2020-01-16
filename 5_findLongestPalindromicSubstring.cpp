/*Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.*/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        int n=s.size(),start=0,maxLen=0;
        for(int i=0;i<n-1;i++){
            findPalindrome(s,i,i,start,maxLen);
            findPalindrome(s,i,i+1,start,maxLen);
        }
          return s.substr(start,maxLen);
    }
    void findPalindrome(string s,int left,int right,int& start,int& maxLen){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            left--;
            right++;
        }
        if(maxLen<right-left-1){
            maxLen=right-left-1;
            start=left+1;
        }
    }
};
