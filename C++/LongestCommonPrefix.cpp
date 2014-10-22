/*
Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0) return "";

        for(auto cnt = 0; cnt != strs[0].size(); ++cnt)
        {
            for(auto it = 0; it != strs.size(); ++it)
            {
                if(strs[it][cnt] != strs[0][cnt]) return strs[0].substr(0,cnt);
            }
        }
        return strs[0];
    }
};
