/*
Given a string containing only digits,
 restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string out;
        restore(s, 4, out, res);
        return res;
    }
    void restore(string s, int k, string out, vector<string>& res){
        if(k == 0){
            if(s.empty()) res.push_back(out);
            return;
        }
        for(int i = 1; i <= 3; i++){
            if(s.size() >= i && isValid(s.substr(0, i))){
                if(k == 1)  restore(s.substr(i), k - 1, out + s.substr(0, i), res);
                else{
                    restore(s.substr(i), k - 1, out + s.substr(0, i) + ".", res);
                }
            }
        }
    }
    bool isValid(string s){
        if(s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
        int m = atoi(s.c_str());

        return m >= 0 && m <= 255;
    }
};
