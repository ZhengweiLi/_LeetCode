/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int a_len = a.size();
        int b_len = b.size();
        bool carry = false;

        int n = max(a_len, b_len);
        if(a_len < b_len){
            a.insert(a.begin(), b_len - a_len, '0');
        }
        else if(a_len > b_len){
            b.insert(b.begin(), a_len - b_len, '0');
        }

        for(int i = n-1; i >= 0; i--){
            int tmp = 0;
            if(carry) tmp = (a[i] - '0') + (b[i]- '0') + 1;
            else{
                tmp = (a[i]- '0') + (b[i] - '0');
            }

            if(tmp == 0){
                res.insert(res.begin(), '0');
                carry = false;
            }
            else if(tmp == 1){
                res.insert(res.begin(), '1');
                carry = false;
            }
            else if(tmp == 2){
                res.insert(res.begin(), '0');
                carry = true;
            }
            else if(tmp == 3){
                res.insert(res.begin(), '1');
                carry = true;
            }

        }
        if(carry) res.insert(res.begin(), '1');
        return res;
    }

};
