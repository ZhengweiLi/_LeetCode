/*Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.*/
class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        unordered_map<char,int>m{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for(int i=0;i<s.size();i++){
            int value=m[s[i]];
            if(i==s.size()-1||m[s[i+1]]<=m[s[i]]) res+=value;
            else res-=value;
        }
        return res;
    }
};
