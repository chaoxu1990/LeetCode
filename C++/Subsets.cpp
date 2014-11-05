/*

Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

//Solution No.1 iteration
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int size = S.size();
        sort(S.begin(), S.end());
        vector<int> tmp;
        vector<vector<int>> result;
        for(int i = 0; i<1<<size; i++)
        {
            for(int j = 0; j<size; j++)
            {
                if(i&1<<j) tmp.push_back(S[j]);
            }
            result.push_back(tmp);
            tmp.clear();
        }
        return result;
    }
};

//Solution No.2 recursion
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int size = S.size();
        sort(S.begin(), S.end());
        vector<vector<int>> result;
        vector<int> tmp;
        helper(result, 0, S, tmp);

        return result;
    }

    void helper(vector<vector<int> > &result, int size, vector<int> S, vector<int> &tmp)
    {
        if(size == S.size())
        {
            result.push_back(tmp);
            return;
        }
        helper(result, size+1, S, tmp);
        tmp.push_back(S[size]);
        helper(result, size+1, S, tmp);
        tmp.pop_back();
    }
};
