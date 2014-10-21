/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string l = "({[", r = ")}]";

        for(auto c:s)
        {
            if(l.find(c) != string::npos)
                st.push(c);
            else if(r.find(c) != string::npos)
            {
                if(st.empty()||st.top() != l[r.find(c)]) return false;
                else st.pop();
            }
        }

        return st.empty();
    }
};
