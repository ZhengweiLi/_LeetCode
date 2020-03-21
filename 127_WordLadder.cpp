/*
Given two words (beginWord and endWord), and a dictionary's word list,
 find the length of shortest transformation sequence from beginWord to endWord,
 such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
 Note that beginWord is not a transformed word.
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5
*/
//solution 1 BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;

        queue<string>q;
        q.push(beginWord);
        unordered_map<string, int>words;
        words[beginWord] = -1;

        int l = beginWord.length();
        int step = 0;

        while(!q.empty()){
            step++;

            for(int size = q.size(); size > 0; size--){
                string w = q.front(); q.pop();
                int loc = words[w];

                for(int i = 0; i < l; i++){
                    char ch = w[i];
                    if(loc == i) continue;

                    for(int j = 'a'; j <= 'z'; j++){
                        w[i] = j;
                        if(w == endWord) return step + 1;
                        if(!dict.count(w)) continue;
                        dict.erase(w);
                        q.push(w);
                        words[w] = i;
                    }
                    w[i] = ch;
                }
            }
        }
        return 0;
    }
};
