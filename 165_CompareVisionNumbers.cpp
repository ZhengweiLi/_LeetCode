/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three",
it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be 0.
For example, version number 3.4 has a revision number of 3 and
4 for its first and second level revision number.
 Its third and fourth level revision number are both 0.



Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
Example 4:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”
Example 5:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number,
 which means its third level revision number is default to "0"*/
 class Solution {
 public:
     int compareVersion(string version1, string version2) {
         string s1, s2;
         int i = 0, j = 0, d1 = 0, d2 = 0;

         while(i < version1.size() || j < version2.size()){
             while(i < version1.size() && version1[i] != '.'){
                 s1.push_back(version1[i++]);
             }
             while(j < version2.size() && version2[j] != '.'){
                 s2.push_back(version2[j++]);
             }

             d1 = atoi(s1.c_str());
             d2 = atoi(s2.c_str());
             if(d1 > d2) return 1;
             else if(d1 < d2) return -1;

             s1.clear(); s2.clear();
             i++; j++;
         }
         return 0;
     }
 };
