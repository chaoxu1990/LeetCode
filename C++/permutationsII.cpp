/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> tmp;
        vector<bool> used(num.size(), false);
        sort(num.begin(), num.end());
        
        helper(num, tmp, result, used);
        
        return result;
    }
    
    void helper(vector<int> &num, vector<int> tmp, vector<vector<int> > &result, vector<bool>& used)
    {
        if(tmp.size() == num.size())
        {
            result.push_back(tmp);
            return;
        }
        
        for(int i = 0; i<num.size(); i++)
        {
            if(used[i] == false)
            {
                if(i>0 && (num[i] == num[i-1]))
                {
                    if(used[i-1] == false) continue;
                }
                    
                tmp.push_back(num[i]);
                used[i] = true;
                helper(num, tmp, result, used);
                tmp.pop_back();
                used[i] = false;
            }
        }
        
        return;
    }
};