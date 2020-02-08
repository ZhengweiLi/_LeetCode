/*
Given two non-negative integers num1 and num2 represented as strings,
return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string res = "";
        vector<int> vals(m+n);

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                int mul = (num1[i] - '0')*(num2[j] - '0');
                int p1 = i + j, p2 = i + j +1;

                int sum = mul + vals[p2];
                vals[p1] += sum / 10;
                vals[p2] = sum % 10;
            }
        }
        for(int val : vals){
            if(!res.empty() || val != 0 ) res.push_back(val + '0');
        }
        return res.empty()? "0":res;
    }
};
