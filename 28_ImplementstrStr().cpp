/*
Implement strStr().

Return the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int m= haystack.size();
        int n= needle.size();
        if(m<n) return -1;

        for(int i=0;i<=m-n;i++){
            if(haystack[i]==needle[0]){
                int j=0;
                for(j=0;j<n;j++){

                    if(haystack[i+j]!=needle[j]) break;
                }
                if(j==n) return i;
            }
        }
        return -1;
    }
};
