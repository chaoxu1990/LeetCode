/*

Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.

*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.size() < 3) return s.size();
        map<char, int> table;
        int start = 0, result = 0;
        for(int i = 0; i<s.size(); ++i)
        {
            if(table.find(s[i]) != table.end() || (table.size() < 2))
                table[s[i]] = i;
            else
            {
                int tmp = i - start;
                result = max(result, tmp);
                map<char, int>::iterator itmin = table.begin();
                for(auto it = table.begin(); it != table.end(); it++)
                {
                    if(it->second < itmin->second)
                        itmin = it;
                }
                start = itmin->second + 1;
                table.erase(itmin);
                table[s[i]] = i;
            }
        }
        int last = s.size() - start;
        result = max(last, result);

        return result;
    }
};
