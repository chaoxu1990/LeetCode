/*

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

*/

class Solution {
public:
    int numDistinct(string S, string T) {
        int ls = S.length(), lt = T.length();
        vector<vector<int> > table(lt+1, vector<int>(ls+1, 0));

        table[0][0] = 1;

        for(int i = 1; i< ls+1; ++i)
            table[0][i] = 1;

        for(int i = 1; i< lt+1; ++i)
            table[i][0] = 0;

        for(int i = 1; i<lt+1; ++i)
        {
            for(int j = 1; j<ls+1; ++j)
            {
                if(S[j-1] == T[i-1])
                    table[i][j] = table[i][j-1] + table[i-1][j-1];
                else
                    table[i][j] = table[i][j-1];
            }
        }

        return table[lt][ls];
    }
};
