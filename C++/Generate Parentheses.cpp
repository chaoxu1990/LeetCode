/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/


class Solution {
public:
    void generator(int n, string s, int l, int r, vector<string> &result)
    {
        if(l==n)
        {
            result.push_back(s.append(n-r, ')'));
            return;
        }
        generator(n, s+'(', l+1, r, result);
        if(l>r) generator(n, s+')', l, r+1, result);
    }


public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        if(n > 0) generator(n, "", 0, 0, result);

        return result;
    }
};



//another better solution
// @author 连城 (http://weibo.com/lianchengzju)

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0) return vector<string> (1,"");
        if(n==1) return vector<string> (1,"()");


        vector<string> result;

        for(int i = 0; i < n; ++i)
            for(auto inner: generateParenthesis(i))
                for(auto outer: generateParenthesis(n-i-1))
                    result.push_back("(" + inner + ")" + outer);

        return result;
    }
};

