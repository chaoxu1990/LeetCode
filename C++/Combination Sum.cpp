/*

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]

*/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> tmp_result;
        sort(candidates.begin(), candidates.end());
        return helper(candidates, target, tmp_result, result, 0);
    }

    vector<vector<int> > helper(vector<int> &candidates, int target, vector<int> &tmp_result, vector<vector<int> > &result, int index)
    {
        if(target < 0) return result;
        if(target == 0){result.push_back(tmp_result); return result;}
        if(index >= candidates.size()) return result;

        for(int i = index; i<candidates.size(); ++i)
        {
            if(target<candidates[i]) break;
            tmp_result.push_back(candidates[i]);
            helper(candidates, target - candidates[i], tmp_result, result, i);
            tmp_result.pop_back();
        }

        return result;
    }
};
