/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> tmp_result;

        helper(result, tmp_result, s, 0);

        return result;
    }

    void helper(vector<vector<string>> &result, vector<string> &tmp_result, string s, int cur)
    {
        if(cur >= s.size())
        {
            result.push_back(tmp_result);
        }

        for(int i = cur; i<s.size(); ++i)
        {
            string left = s.substr(cur,i-cur+1);
            if(isPalindrome(left))
            {
                tmp_result.push_back(left);
                helper(result, tmp_result, s, i+1);
                tmp_result.pop_back();
            }
        }
    }

    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while(i<j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            return false;
        }

        return true;
    }
};
