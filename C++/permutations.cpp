/*

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

*/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {

        vector<vector<int> > result;
        vector<int> tmp_result;

        helper(result, tmp_result, num);

        return result;
    }

    void helper(vector<vector<int> > &result, vector<int> &tmp_result, vector<int> &num)
    {
        if(tmp_result.size() == num.size())
        {
            result.push_back(tmp_result);
            return;
        }

        for(int i = 0; i<num.size(); ++i)
        {
            if(find(tmp_result.begin(), tmp_result.end(), num[i]) == tmp_result.end())
            {
                tmp_result.push_back(num[i]);
                helper(result, tmp_result, num);
                tmp_result.pop_back();
            }
        }
        return;
    }
};


//Another solution using O(n) space
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> tmp;
        vector<bool> used(num.size(), false);
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