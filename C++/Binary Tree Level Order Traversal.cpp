/*

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        helper(root, result, 0);
        return result;
    }

    void helper(TreeNode *root, vector<vector<int> > &result, int level)
    {
        if(root == NULL) return;
        if(result.size()<=level) result.push_back(vector<int>());
        result[level].push_back(root->val);
        helper(root->left, result, level+1);
        helper(root->right, result, level+1);
        return;
    }
};
