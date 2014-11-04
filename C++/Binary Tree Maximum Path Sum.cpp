/*

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

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
    int maxSum;
    int maxPathSum(TreeNode *root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }
    int dfs(TreeNode *root)
    {
        if(!root) return 0;
        int sum = root->val;
        int l = dfs(root->left), r = dfs(root->right);
        if(l>0) sum += l;
        if(r>0) sum += r;

        maxSum = max(maxSum, sum);

        return max(l,r)>0?max(l,r) + root->val:root->val;
    }
};
