/*
Given an absolute path for a file (Unix-style), simplify it.
Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory.
 Furthermore, a double period .. moves the directory up a level. For more information,
 see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /,
and there must be only a single slash / between two directory names.
The last directory name (if it exists) must not end with a trailing /.
 Also, the canonical path must be the shortest string representing the absolute path.

 Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
*/
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;

        while(i < path.size()){
            while(path[i] == '/' && i < path.size()) i++;
            if(i == path.size()) break;

            int begin = i;
            while(path[i] != '/' && i < path.size()) i++;
            int end = i-1;

            string s = path.substr(begin, end-begin+1);
            if(s == ".."){
                if(!v.empty()) v.pop_back();
            }
            else if(s != "."){
                v.push_back(s);
            }
        }
        string res;
        if(v.empty()) return "/";
        for(int i = 0; i < v.size(); i++){

            res += '/' + v[i];
        }
        return res;
    }
};
