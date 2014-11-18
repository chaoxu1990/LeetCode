/*

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string tmp;
        vector<string> result;

        helper(s, tmp, result, 0, 0);

        return result;
    }


    void helper(string s, string tmp, vector<string>& result, int start, int step)
    {
        if(step == 4 && start == s.size())
        {
            tmp.erase(tmp.end()-1);
            result.push_back(tmp);
            return;
        }

        if(s.size() - start > (4-step) * 3 ) return;
        if(s.size() - start < 4-step) return;
        int num = 0;
        for(int i = start; i<3+start; ++i)
        {
            num = num * 10 + (s[i] - '0');
            if(num <= 255)
            {
                tmp += s[i];
                helper(s, tmp + '.', result, 1 + i, step + 1);
            }
            if(num == 0) break;
        }

        return;
    }
};
