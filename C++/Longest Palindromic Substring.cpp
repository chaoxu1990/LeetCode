/*

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(), max = 1, start = 0;
        bool table[len][len];
        memset(table,false,sizeof(table));

        for(int i = 0; i<len; ++i)
        {
            table[i][i] = true;
            for(int j = 0; j<i; ++j)
            {
                table[i][j] = ((s[i] == s[j])&&(i-j<2 || table[i-1][j+1]));
                if(table[i][j] && max < i - j + 1)
                {
                    start = j;
                    max = i - j + 1;
                }
            }
        }
        return s.substr(start, max);
    }
};
