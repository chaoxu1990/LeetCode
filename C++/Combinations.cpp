/*

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> tmp;
        helper(n,k,result,tmp,1);
        return result;
    }

    void helper(int n, int k,vector<vector<int> > &result, vector<int> &tmp, int cur)
    {

        if(tmp.size() == k)
        {
            result.push_back(tmp);
            return;
        }
        if(cur > n) return;
        tmp.push_back(cur);
        helper(n,k,result, tmp, cur + 1);
        tmp.pop_back();
        helper(n,k,result, tmp, cur + 1);
    }
};
