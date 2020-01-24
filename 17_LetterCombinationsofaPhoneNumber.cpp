/*
Given a string containing digits from 2-9inclusive,
return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
Note that 1 does not map to any letters.
Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string>res;
        vector<string>dict{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        letterCombinationsDFS(digits,dict,0,"",res);
        return res;

    }
    void letterCombinationsDFS(string& digits,vector<string>&dict,int level,string out,vector<string>&res){
        if(level==digits.size()){res.push_back(out);return;}
        string str=dict[digits[level]-'0'];
        for(int j=0;j<str.size();j++){
            letterCombinationsDFS(digits,dict,level+1,out+str[j],res);
        }
    }
};
