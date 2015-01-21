/*

Given two strings S and T, determine if they are both one edit distance apart.

*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size() < t.size()) swap(s,t);
        int slen = s.size(), tlen = t.size();
        if(slen - tlen > 1) return false;
        int i = 0, j = 0;
        int diffcount = 0;
        while(i<slen)
        {
            if(s[i] != t[j])
            {
                diffcount++;
                i++;
                if(slen == tlen) j++;
                continue;
            }
            i++;
            j++;
        }

        return diffcount == 1;
    }
};

//上面那个解法虽然能过leetcode，但是j有可能会走到t[t.size()],虽然不会数组越界（是'\0')， 但是也不太好。
//比如 s = "abc", t = "ab";

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size() < t.size()) swap(s,t);
        if(s.size() > t.size() + 1) return false;
        int dist = 0;
        for(int i = 0, j = 0; i<s.size() && j<t.size();i++, j++)
        {
            if(s[i] != t[j])
            {
                dist++;
                if(s.size() != t.size())
                j--;
            }
        }
        return dist == 1 || (dist == 0 && s.size() == t.size()+1);
    }
}
