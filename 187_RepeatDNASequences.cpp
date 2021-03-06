/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
for example: "ACGAATTCCG". When studying DNA, it is sometimes useful
to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings)
that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size() <= 10) return res;
        int mask = 0x7ffffff, cur = 0;
        unordered_map<int, int> m;

        for(int i = 0; i < 9; i++){
            cur = (cur << 3) | (s[i] & 7);
        }
        for(int i = 9; i < s.size(); i++){
            cur = ((cur & mask) << 3) | (s[i] & 7);
            if(m.count(cur)){
                if(m[cur] == 1) res.push_back(s.substr(i - 9, 10));
                ++m[cur];
            }
            else{
                m[cur] = 1;
            }
        }
        return res;
    }
};
