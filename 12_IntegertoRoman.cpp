/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900*/
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<char> roman{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        vector<int> value{1000, 500, 100, 50, 10, 5, 1};
        for (int n = 0; n < 7; n += 2) {
            int x = num / value[n];
            if (x < 4) {
                for (int i = 1; i <= x; ++i) res += roman[n];
            } else if (x == 4) {
                res = res + roman[n] + roman[n - 1];
            } else if (x > 4 && x < 9) {
                res += roman[n - 1];
                for (int i = 6; i <= x; ++i) res += roman[n];
            } else if (x == 9) {
                res = res + roman[n] + roman[n - 2];//res+=roman[n]+roman[n-2]报错
            }
            num %= value[n];
        }
        return res;
    }
};
//补充知识：string对象可以与字符字面值或字符串字面值相加，但是+两侧至少要有一个string对象
//         res = res + roman[n] + roman[n - 2];正确，先运算res + roman[n]， 转化为一个新的string对象，再与roman[n - 2]相加。
//         res+=roman[n]+roman[n-2];报错，+=优先级低于+，先运算roman[n]+roman[n-2],不能把两个字符字面值相加。
