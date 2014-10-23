/*

Given a string, find the length of the longest substring without repeating
characters. For example, the longest substring without repeating letters
for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest
substring is "b", with the length of 1.

*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, start = 0;
        int table[256];
        memset(table,-1,256*sizeof(int));
        for(int i = 0; i<s.size(); i++)
        {
            int key = s[i];
            if(table[key] >= start)
            {
                if(maxLen< i - start)
                    maxLen = i - start;
                start = table[key] + 1;
            }
            table[key] = i;
        }
        if(maxLen < s.size()-start) maxLen = s.size() - start;
        return maxLen;
    }
};
