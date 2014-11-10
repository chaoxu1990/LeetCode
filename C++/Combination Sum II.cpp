/*

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

*/

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        vector<int> tmp_result;
        sort(num.begin(), num.end());

        return helper(num, target, result, tmp_result, 0);
    }

    vector<vector<int> > helper(vector<int> & num, int target, vector<vector<int> > &result, vector<int> &tmp_result, int index)
    {
        //if(index >= num.size()) return result;
        if(target < 0) return result;
        if(target == 0)
        {
            result.push_back(tmp_result);
            return result;
        }

        for(int i = index; i<num.size(); ++i)
        {
            if(num[i] > target) break;
            tmp_result.push_back(num[i]);
            helper(num,target-num[i],result, tmp_result, i + 1);
            tmp_result.pop_back();
            while(i<num.size()-1 && num[i] == num[i+1]) i++;

        }

        return result;

    }
};
