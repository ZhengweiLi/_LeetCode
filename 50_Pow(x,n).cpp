/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double half = myPow(x, n/2);

        if(n%2 == 0) return half*half;
        if(n > 0) return half*half*x;
        return half*half/x;
    }
};
