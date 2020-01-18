/*Given a 32-bit signed integer, reverse digits of an integer.
*
*Example 1:
*
*Input: 123
*Output: 321*/
class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x!=0){
            if(abs(res)>INT_MAX/10) return 0;
            res=res*10+x%10;
            x/=10;
        }
        return res;
    }
};
