/*

Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

*/

class Solution {
public:
    bool isvalid(string start, string end)
    {
        bool find = false;
        if(start.size() != end.size())
        return false;
        for(int i = 0; i<start.size(); i++)
        {
            if(start[i] != end[i])
            {
                if(find == false)
                    find = true;
                else
                    return false;
            }
        }
        return true;
    }

    class node{
        public:
        int level;
        string word;
        node(string w, int l):level(l), word(w){}
    };

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, bool> table;
        queue<node> x;
        node tmp(start, 1);
        x.push(tmp);

        for(unordered_set<string>::iterator it = dict.begin(); it!=dict.end(); ++it)
        {
            table[*it] = false;
        }
        table[start] = false;
        table[end] = false;

        while(x.empty() == false)
        {
            string s = x.front().word;
            int level = x.front().level;
            if(isvalid(s,end) == true)
                return level+1;
            x.pop();
            if(table[s] == true) continue;
            else table[s] = true;
            for(int i = 0; i<s.size(); ++i)
            {
                string ss = s;
                for(int j = 0; j<26; j++)
                {
                    ss[i] = j + 'a';
                    if(dict.find(ss) != dict.end() && ss != s)
                    {

                        node tmp(ss,level+1);
                        x.push(tmp);
                    }
                }
            }
        }

        return 0;
    }
};
