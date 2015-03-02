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
        vector<string> ret;
        string tmp;
        vector<bool> table(s.size() + 1, true);
        
        DFS(s, dict, tmp, ret, table, 0);
        
        return ret;
    }
    
    void DFS(string s, unordered_set<string> &dict, string tmp, vector<string> &ret, vector<bool> &table, int depth)
    {
        if(depth == s.size())
        {
            tmp.pop_back();
            ret.push_back(tmp);
            return;
        }
        
        
        for(int i = depth + 1; i <= s.size(); i++)
        {
           string cur = s.substr(depth, i-depth);
           if(dict.find(cur) != dict.end() && table[depth] == true)
           {
                int size = ret.size();
                DFS(s, dict, tmp + cur + " ", ret, table, i);
                if(ret.size() == size)
                table[i] = false;
           }
        }
    }
};