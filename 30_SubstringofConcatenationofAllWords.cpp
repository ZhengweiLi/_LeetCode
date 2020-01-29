/*
You are given a string, s, and a list of words, words,
that are all of the same length. Find all starting indices of substring(s) in s
that is a concatenation of each word in words exactly once and without any intervening characters.


Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty()||words.empty()) return {};
        unordered_map<string,int>wordCnt;
        int n=words.size(),len=words[0].size();
        vector<int>res;

        for(auto &word:words) ++wordCnt[word];
        for(int i=0;i<=(int)s.size()-n*len;i++){

            unordered_map<string,int>strCnt;
            int j=0;
            for(j=0;j<n;j++){

                string t=s.substr(i+j*len,len);
                if(!wordCnt.count(t)) break;
                ++strCnt[t];
                if(strCnt[t]>wordCnt[t]) break;
            }
            if(j==n) res.push_back(i);
        }
        return res;
    }
};
