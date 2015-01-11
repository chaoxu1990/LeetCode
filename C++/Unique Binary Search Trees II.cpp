/*

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> result;
        helper(1, n, result);
        return result;
    }
    void helper(int left, int right, vector<TreeNode*>& result)
    {
        if(left>right)
        {
            result.push_back(NULL);
            return;
        }
        for(int i = left; i<=right; i++)
        {
            vector<TreeNode *> sl, sr;
            helper(left, i-1, sl);
            helper(i+1, right, sr);
            for(auto l: sl)
                for(auto r: sr)
                {
                    TreeNode *tmp = new TreeNode(i);
                    tmp->left = l;
                    tmp->right = r;
                    result.push_back(tmp);
                }
        }
    }
};
