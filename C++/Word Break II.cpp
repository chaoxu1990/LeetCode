/*

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

*/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> result;
        if(s.size() == 0) return result;
        string tmp = "";
        vector<bool> check(s.size(), true);
        helper(result, tmp, 0, s, dict, check);
        return result;
    }

    void helper(vector<string> &result, string &tmp, int index, string s, unordered_set<string> &dict, vector<bool>& check)
    {
        if(index >= s.size())
        {
            tmp.erase(tmp.end()-1);
            result.push_back(tmp);
            return;
        }

        for(int i = 1; i + index<=s.size(); ++i)
        {
            string cur = s.substr(index, i);
            if(dict.find(cur) != dict.end() && check[i+index] == true)
            {
                string old_tmp = tmp;
                tmp = tmp + cur + " ";
                int size = result.size();
                helper(result, tmp, index + i, s, dict, check);
                tmp = old_tmp;
                if(size == result.size())
                    check[i+index] = false;
            }
        }
    }
};
