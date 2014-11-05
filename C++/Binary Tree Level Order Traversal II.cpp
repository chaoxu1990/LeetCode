/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
         vector<vector<int> > result;
         int level = depth(root);
         while(result.size()<level) result.push_back(vector<int>());

         helper(root, result, level);
         return result;
    }
    int depth(TreeNode*root)
    {
        if(root == NULL) return 0;
        int a = depth(root->left);
        int b = depth(root->right);

        return max(a,b)+1;
    }
    void helper(TreeNode *root, vector<vector<int> > &result, int level)
    {
        if(root == NULL) return;
        helper(root->left, result, level-1);
        helper(root->right, result, level-1);

        result[level-1].push_back(root->val);

        return;
    }
};
