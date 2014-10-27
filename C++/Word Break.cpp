/*

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> result(s.size() + 1, false);
        result[0] = true;
        for(int i = 0; i <= s.size(); ++i)
        {
            for(int j = i; j>=0; --j)
            {
                if(result[j] && dict.find(s.substr(j, i-j)) != dict.end())
                {
                    result[i] = true;
                    break;
                }
            }
        }

        return result[s.size()];
    }
};
