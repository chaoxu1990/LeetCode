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


//Solution No.2

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string>  old_que;
        int result = 2;
        if(dict.find(start) != dict.end())dict.erase(start);
        if(dict.find(end) != dict.end())dict.erase(end);
        
        old_que.push(start);

        while(1)
        {
            queue<string> new_que;
            while(old_que.empty() == false)
            {
                string cur = old_que.front();
                old_que.pop();
                

                for(int i = 0; i<cur.size(); i++)
                {
                    string tmp = cur;                    
                    for(int j = 0; j < 26; ++j)
                    {
                        if(tmp[i] == j + 'a') continue;
                            
                        tmp[i] = j + 'a';
                        if(tmp == end)
                            return result;
                        if(dict.find(tmp) != dict.end())
                        {
                            dict.erase(tmp);
                            new_que.push(tmp);
                        }
                    }
                }
            }
            if(new_que.empty() == true) break;
            old_que = new_que;
            result++;
        }
        
        return 0;
    }
};



//Solution No.3
//Using Bi-directional search
class Solution {
public:
    class node{
        public:
        string s;
        int level;
        node(string str, int le):s(str), level(le){};
    };
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end) return 0;
        unordered_map<string, bool> m1, m2;
        queue<node> q1, q2;
        node st(start, 1);
        node en(end, 1);
        bool found = false;
        q1.push(st), q2.push(en);
        for(auto s:dict)
        {
            m1[s] = false;
            m2[s] = false;
        }
        m1[start] = true;
        m2[end] = true;
        
        while(q1.empty() == false && q2.empty() == false)
        {
            if(q1.size() < q2.size())
            {
                if(BFS(q1, m1, m2, dict)) return q1.front().level + q2.back().level;                
            }
            else
            {
                if(BFS(q2, m2, m1, dict)) return q2.front().level + q1.back().level;
            }
        }
        return 0;
    }
    bool BFS(queue<node> &q, unordered_map<string, bool> &m, unordered_map<string, bool> &c, unordered_set<string> &dict)
    {
        int lev = q.front().level;
        while(q.empty() == false && q.front().level == lev)
        {
            node nq = q.front();
            string tmp = nq.s;
            int l = nq.level;
            string old = tmp;
            for(int i = 0; i<tmp.size();i++)
            {
                tmp = old;
                for(int j = 0; j<26; j++)
                {
                    tmp[i] = j+'a';
                    if(tmp == old) continue;
                    if(dict.find(tmp) != dict.end() && !m[tmp])
                    {
                        m[tmp] = true;
                        if(c[tmp] == true) return true;
                        q.push(node(tmp, l+1));
                    }
                }
            }
            q.pop();
        }
        return false;
    }
};