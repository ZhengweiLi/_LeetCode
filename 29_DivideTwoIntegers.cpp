/*
Given two integers dividend and divisor, divide two integers without using multiplication,
division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3

Example 2:
Input: dividend = 7, divisor = -3
Output: -2

*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
        long m=labs(dividend),n=labs(divisor),res=0;
        int sign=((dividend<0)^(divisor<0))?-1:1;
        if(n==1) return (sign==1)?m:-m;

        while(m>=n){
            long t=n,p=1;
            while(m>=(t<<1)){
                t<<=1;
                p<<=1;
            }
            res+=p;
            m-=t;
        }
        return (sign==1)?res:-res;
    }
};
