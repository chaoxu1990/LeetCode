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
