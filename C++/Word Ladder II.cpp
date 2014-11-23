/*

Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

*/

class Solution {
public:
    map<string, vector<string>> table;
    vector<vector<string>> result;
    vector<string> tmp;
    void findNext(string str, unordered_set<string>& next, unordered_set<string> &dict)
    {
        for(int i = 0; i<str.size(); ++i)
        {
            string s = str;
            for(int j = 0; j<26; ++j)
            {
                s[i] = j + 'a';
                if(dict.find(s) != dict.end())
                {
                    next.insert(s);
                    table[s].push_back(str);
                }
            }
        }
    }

    void output(string start, string end)
    {
        if(end == start)
        {
            result.push_back(tmp);
            return;
        }
        for(int i = 0; i<table[end].size(); ++i)
        {
            tmp.insert(tmp.begin(), table[end][i]);
            output(start, table[end][i]);
            tmp.erase(tmp.begin());
        }
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        table.clear();
        result.clear();
        tmp.clear();
        unordered_set<string> cur_level, next_level;
        dict.insert(start);
        cur_level.insert(start);
        dict.insert(end);
        tmp.push_back(end);

        while(true)
        {
            for(auto it = cur_level.begin(); it!=cur_level.end(); ++it)
            {dict.erase(*it);}
            for(auto it = cur_level.begin(); it!=cur_level.end(); ++it)
            {findNext(*it, next_level,dict);}

            if(next_level.empty())
                return result;
            if(next_level.find(end) != next_level.end())
            {
                output(start, end);
                return result;
            }
            cur_level.clear();
            cur_level = next_level;
            next_level.clear();
        }
    }
};
