/*

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        helper(root, 0, result, true);
        return result;
    }

    void helper(TreeNode *root, int level, vector<vector<int>>& result, bool leftToRight)
    {
        if(!root) return;
        if(level >= result.size())
        result.push_back(vector<int>());
        if(leftToRight)
            result[level].push_back(root->val);
        else
            result[level].insert(result[level].begin(), root->val);

        helper(root->left, level+1, result, !leftToRight);
        helper(root->right, level+1, result, !leftToRight);
    }
};
