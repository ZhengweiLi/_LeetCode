/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /.
Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid.
 That means the expression would always evaluate to a result and
 there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation:
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1) return stoi(tokens[0]);
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/" ){
                st.push(stoi(tokens[i]));
            }
            else{
                int nums1 = st.top(); st.pop();
                int nums2 = st.top(); st.pop();

                if(tokens[i] == "+") st.push(nums2 + nums1);
                if(tokens[i] == "-") st.push(nums2 - nums1);
                if(tokens[i] == "*") st.push(nums2 * nums1);
                if(tokens[i] == "/") st.push(nums2 / nums1);
            }
        }
        return st.top();
    }
};
