/*

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

*/

//Solution No.1 recursion, will get Time Limit Exceeded(TLE)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        return helper(s1,s2,s3,0,0,0);
    }

    bool helper(string s1, string s2, string s3, int l1, int l2, int l3)
    {
        if(l1>s1.length() || l2 > s2.length()) return false;
        if(l3 == s3.length())
        {
            if(((s3[l3-1] == s1[l1-1])||(s3[l3-1] == s2[l2-1]))&&((l1==s1.length())&&(l2 == s2.length())))
            return true;
            else
            return false;
        }

        if(s3[l3] != s1[l1] && s3[l3] != s2[l2])
            return false;

        return ((s1[l1] == s3[l3]) && helper(s1,s2,s3, l1+1, l2, l3+1) )
            || ((s2[l2] == s3[l3]) && helper(s1,s2,s3, l1, l2+1, l3+1));
    }
};

//Solution No.2 DP
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(l1 + l2 != l3) return false;
        vector<vector<bool> > table(l1+1, vector<bool>(l2+1, false));

        table[0][0] = true;
        for(int i = 1; i<l2+1; ++i)
        {
            if(table[0][i-1] == true && s2[i-1] == s3[i-1])
                table[0][i] = true;
        }

        for(int i = 1; i<l1+1; ++i)
        {
            if(table[i-1][0] == true && s1[i-1] == s3[i-1])
                table[i][0] = true;
        }

        for(int i = 1; i < l1+1; ++i)
        {
            for(int j = 1; j < l2+1; ++j)
            {
                if(table[i-1][j] == true && s1[i-1] == s3[i+j-1]
                   || table[i][j-1] == true && s2[j-1] == s3[i+j-1])
                    table[i][j] = true;
            }
        }

        return table[l1][l2];
    }
};
