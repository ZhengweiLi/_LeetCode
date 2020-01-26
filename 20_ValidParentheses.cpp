/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.
An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
Input: "([)]"
Output: false
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for(int i=0;i<s.size();i++){

            if(s[i]=='('||s[i]=='['||s[i]=='{') parentheses.push(s[i]);
            else{
                if(parentheses.empty()) return false;
                if(s[i]==')'&&parentheses.top()!='(') return false;
                if(s[i]==']'&&parentheses.top()!='[') return false;
                if(s[i]=='}'&&parentheses.top()!='{') return false;
                parentheses.pop();
            }
        }

        return parentheses.empty();
    }
};
