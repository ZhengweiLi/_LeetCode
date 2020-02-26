/*
Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous.
You should gather all requirements up front before implementing one.
However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.
*/
class Solution {
public:
    bool isNumber(string s) {
        int  n = s.size();
        bool dot = false, num = false, numAfterE = true, exp = false, sign = false;

        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                if(i < n-1 && s[i+1] != ' ' && (dot || num || exp || sign)) return false;
            }
            else if(s[i] >= '0' && s[i] <= '9') {
                num = true;
                numAfterE = true;
            }
            else if( s[i] == '+' || s[i] == '-'){
                if(i > 0 && (s[i-1] != ' ' && s[i-1] != 'e')) return false;
                sign = true;
            }
            else if(s[i] == 'e'){
                if(exp || !num) return false;
                exp = true;
                numAfterE = false;
            }
            else if(s[i] == '.'){
                if(dot || exp) return false;
                dot = true;
            }
            else return false;
        }
        return num && numAfterE;
    }
};
