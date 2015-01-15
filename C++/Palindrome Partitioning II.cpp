/*

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

*/

class Solution {
public:
    int minCut(string s) {
        vector<vector<bool> > table(s.size(), vector<bool>(s.size(), false));
        vector<int> res(s.size(), 0);
        for(int i = 0; i<s.size(); ++i)
            res[i] = i;

        for(int i = s.size()-1; i>=0; --i)
        {
            for(int j = i; j<s.size(); ++j)
            {
                if(s[i]==s[j] && ( j-i<2 || table[i+1][j-1] == true))
                    table[i][j] = true;
                else
                    table[i][j] = false;
            }
        }

        for(int i = 0; i<s.size(); ++i)
        {
            if(table[0][i] == true)
                res[i] = 0;
            else
            {
                for(int j = 0; j<i; ++j)
                {
                    if(table[j+1][i] == true)
                        res[i] = min(res[i], res[j] + 1);
                }
            }
        }


        return res[s.size() - 1];
    }
};


//A more concise solution
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<vector<bool> > table(len, vector<bool>(len, false));
        vector<int> res(len+1, INT_MAX);
        for(int i = 0; i<=len; i++)res[i] = len - i - 1;
        
        
        for(int i = len-1; i>-1; i--)
            for(int j = i; j<len; j++)
                if((s[i] == s[j]) && ((j-i < 2) || (table[i+1][j-1] == true)))
                {
                    table[i][j] = true;
                    res[i] = min(res[i], res[j+1] + 1);
                }
        
        
        return res[0];
    }
};
