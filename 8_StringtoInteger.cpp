/*Implement atoi which converts a string to an integer.*/
class Solution {
public:
    int myAtoi(string str) {
        int i=0,sign=1,base=0,n=str.size();
        if(str.empty()) return 0;
        while(i<n&&str[i]==' ') i++;
        if(i<n&&(str[i]=='+'||str[i]=='-')){
            sign=(str[i++]=='+')?1:-1;
        }
        while(i<n&&(str[i]>='0'&&str[i]<='9')){
            if(base>INT_MAX/10||(base==INT_MAX/10&&str[i]-'0'>7)){
                return (sign==1)?INT_MAX:INT_MIN;
            }
            base=base*10+(str[i++]-'0');
        }
        return base*sign;
    }
};
