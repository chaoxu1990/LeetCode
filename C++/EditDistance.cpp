/*

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*/

class Solution {
public:
    int findMin(int a, int b, int c)
    {
        int res = 0;
        if(a<b)
            res = a;
        else
            res = b;

        if(res < c)
            return res;
        else
            return c;
    }

    int minDistance(string word1, string word2) {
        int r = word1.size(), c = word2.size();
        int table[r+1][c+1];

        memset(table, 0, sizeof(table));

        for(int i = 0; i<=r; ++i)
            table[i][0] = i;
        for(int i = 0; i<=c; ++i)
            table[0][i] = i;

        for(int i = 1; i<=r; ++i)
            for(int j = 1; j<=c; ++j)
            {
                if(word1[i-1] == word2[j-1])
                    table[i][j] = table[i-1][j-1];
                else
                    table[i][j] = findMin(table[i-1][j], table[i][j-1], table[i-1][j-1])+1;
            }


        return table[r][c];

    }
};
