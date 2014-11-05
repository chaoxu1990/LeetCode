/*

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/


class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
         int size = S.size();
        sort(S.begin(), S.end());
        vector<vector<int>> result;
        vector<int> tmp;
        helper(result, 0, S, tmp);

        return result;
    }

    void helper(vector<vector<int> > &result, int size, vector<int> S, vector<int> &tmp)
    {
        result.push_back(tmp);

        for(int i = size; i<S.size(); ++i)
        {
            if(i!= size && S[i] == S[i-1]) continue;
            tmp.push_back(S[i]);
            helper(result, i+1, S, tmp);
            tmp.pop_back();
        }
    }
};
