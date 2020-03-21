/*
Given a string s, partition s such that every substring of the partition
is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        helper(s, 0, out, res);
        return res;
    }
    void helper(string s, int start, vector<string>& out, vector<vector<string>>& res){
        if(start == s.size()) {res.push_back(out); return;}
        for(int i = start; i < s.size(); i++){

            if(!isPalindrome(s, start, i)) continue;

            out.push_back(s.substr(start, i - start + 1));
            helper(s, i + 1, out, res);
            out.pop_back();

        }
    }
    bool isPalindrome(string s, int begin, int end){
        while(begin < end){

            if(s[begin] != s[end]) return false;
            begin++;
            end--;
        }
        return true;
    }
};
