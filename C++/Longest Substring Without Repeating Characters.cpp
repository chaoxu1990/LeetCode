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

//Another version using two pointers and hashset

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> helper;
        int p1= 0, p2 = 0, result = 0, tmp_result = 0;
        while(p2 < s.length())
        {
            if(helper.find(s[p2]) == helper.end())
                helper.insert(s[p2]);
            else
            {
                result = max(result, p2-p1);
                while(s[p2] != s[p1++])
                    helper.erase(s[p1-1]);
            }
            p2++;
        }
        return max(result, p2-p1);
    }
};

