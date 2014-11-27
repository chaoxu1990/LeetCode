/*

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

*/
//Solutin No.1 Stack
class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        stack<int> sta;
        for(int i = 0; i<s.size(); ++i)
        {
           if(s[i] == '(')
           sta.push(i);
           else
           {
               if(sta.empty() == false && s[sta.top()] == '(')
               {
                   sta.pop();
                   result = max(result, i - (sta.empty()?-1:sta.top()));
               }
               else
               {
                   sta.push(i);
               }
           }
        }

        return result;
    }
};

//Solution No.2 DP
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0) return 0;
        int result = 0;
        vector<int> table(s.size(), 0);
        for(int i = 1; i<s.size(); ++i)
        {
            if(s[i] == ')')
            {
                int j = i-1-table[i-1];
                if(j>=0 && s[j] == '(')
                {
                    //case: "(((...)))"
                    table[i] = table[i-1] + 2;
                    if(j-1 >= 0)//case: "(((...)))()()"
                    table[i] += table[j-1];
                }
            }
            result = max(table[i], result);
        }
        return result;
    }
};
