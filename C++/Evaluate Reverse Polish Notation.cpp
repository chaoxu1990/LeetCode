/*

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

class Solution {
public:
    int strtoInt(string s)
    {
        int result = 0;
        bool neg = false;
        for(size_t i = 0; i<s.size(); ++i)
        {
            if(s[i] == '-'){neg = true; continue;}
            result = result*10 + s[i] - '0';
        }

        return neg?result*-1:result;
    }
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        int result = 0;
        for(size_t i = 0; i<tokens.size(); ++i)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                switch (tokens[i][0])
                {
                    case '+':
                    result = op2 + op1;
                    st.push(result);
                    break;

                    case '-':
                    result = op2 - op1;
                    st.push(result);
                    break;

                    case '*':
                    result = op2 * op1;
                    st.push(result);
                    break;

                    case '/':
                    result = op2 / op1;
                    st.push(result);
                    break;
                }
            }
            else
            {
                st.push(strtoInt(tokens[i]));
            }
        }
        return st.top();
    }
};
