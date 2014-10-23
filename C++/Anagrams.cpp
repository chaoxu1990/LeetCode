/*

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string>> groups;

        for(auto s: strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        vector<string> result;
        for(map<string, vector<string>>::iterator it = groups.begin(); it!=groups.end(); ++it)
        {
            if((it->second).size()>1)
            result.insert(result.begin(), it->second.begin(), it->second.end());
        }
        return result;
    }
};
