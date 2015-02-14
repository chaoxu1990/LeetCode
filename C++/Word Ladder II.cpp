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


//Solution No.2
//Using Bi-BFS, only take 131ms
class Solution {
public:
    vector<vector<string> > result;
    vector<string> tmp;
    unordered_map<string, unordered_set<string> > table;

    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        tmp.clear();
        result.clear();
        table.clear();
        unordered_map<string, bool> m1, m2;
        queue<pair<string, int> > q1, q2;
        bool found = false;
        q1.push(pair<string, int>(start, 1));
        q2.push(pair<string, int>(end,1));
        tmp.push_back(start);
        for(auto s: dict)
        {
            m1[s] = false;
            m2[s] = false;
        }
        m1[start] = true;
        m2[end] = true;

        while(q1.empty() == false && q2.empty() == false)
        {
            if(q1.size() < q2.size())
                found = BFS(q1, m1, m2, dict, table, true);
            else
                found = BFS(q2, m2, m1, dict, table, false);

            if(found) {output(start, end); break;}
        }

        return result;
    }

     void output(string start, string end)
    {
        if(end == start)
        {
            result.push_back(tmp);
            return;
        }
        for(auto it = table[start].begin(); it != table[start].end(); it++)
        {
            tmp.push_back(*it);
            output(*it, end);
            tmp.pop_back();
        }
    }
    bool BFS(queue<pair<string, int> > &q, unordered_map<string, bool> &m, unordered_map<string, bool> &c, unordered_set<string> &dict, unordered_map<string, unordered_set<string> > &table, const bool flag)
    {
        bool found = false;
        int level = q.front().second;
        unordered_set<string> cur;
        while(q.empty() == false && q.front().second == level)
        {
            string tmp = q.front().first;
            string old = tmp;

            for(int i = 0; i<old.size(); i++)
            {
                tmp = old;
                for(int j = 0; j<26; j++)
                {
                    tmp[i] = j + 'a';
                    if(tmp == old) continue;
                    if(dict.find(tmp) != dict.end() && !m[tmp])
                    {
                        cur.insert(tmp);
                        if(flag)
                            table[old].insert(tmp);
                        else
                            table[tmp].insert(old);
                        if(c[tmp] == true) found = true;
                        q.push(pair<string, int>(tmp, level+1));
                    }
                }
            }
            q.pop();
        }
        for(auto it: cur)
            m[it] = true;
        return found;
    }
};
