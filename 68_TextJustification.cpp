/*
Given an array of words and a width maxWidth,
 format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach;
that is, pack as many words as you can in each line.
Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words,
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.
Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, L = maxWidth;

        while(i < words.size()){
            int j = i, len = 0;
            while(j < words.size() && len + words[j].size() + j-i <= L){
                len += words[j++].size();
            }

            int space = L - len;
            string out;
            for(int k = i; k < j; k++){
                int tmp = 0;
                out += words[k];

                if(space > 0){
                    if(j == words.size()){
                        if(j - k == 1){
                            tmp = space;
                        }
                        else tmp = 1;
                    }
                    else if(j-k-1 > 0){
                        if(space % (j-k-1) == 0) tmp = space / (j-k-1);
                        else tmp = space / (j-k-1) + 1;
                    }
                    else tmp = space;

                }
                space -= tmp;
                out.append(tmp, ' ');
            }
            i = j;
         res.push_back(out);
        }
        return res;
    }
};
