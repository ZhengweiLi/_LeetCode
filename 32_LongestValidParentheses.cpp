/*
Given a string containing just the characters '(' and ')',
 find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),res=0,start=0;
        stack<int>st;
        for(int i=0;i<n;i++){

            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(st.empty()) start=i+1;
                else{
                    st.pop();
                    res=st.empty()?max(res,i-start+1):max(res,i-st.top());
                }

            }
        }
        return res;
    }
};
