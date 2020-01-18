/*Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.


The matching should cover the entire input string (not partial).

Note:
•s could be empty and contains only lowercase letters a-z.
•p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p.size()==1){
            return (s.size()==1&&(p[0]==s[0]||p[0]=='.'));
        }
        if(p[1]!='*'){
            if(s.empty()) return false;
            return (p[0]==s[0]||( p[0]=='.'))&&isMatch(s.substr(1),p.substr(1));
                    }
        while(!s.empty()&&(p[0]==s[0]||p[0]=='.')){
            if(isMatch(s,p.substr(2))) return true;
            s=s.substr(1);
        }
        return isMatch(s,p.substr(2));
    }
};
