/*

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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

//Solution No.1:
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL) return 0;
        int a,b;
        if(root->left != NULL && root->right != NULL)
        {
            a = minDepth(root->left);
            b = minDepth(root->right);
        }
        else if(root->left == NULL && root->right != NULL )
        {
            a = INT_MAX;
            b = minDepth(root->right);
        }
        else if(root->right == NULL && root->left != NULL)
        {
            a = minDepth(root->left);
            b = INT_MAX;
        }
        else if(root->left == NULL && root->right == NULL)
        {
            a = 0;
            b = 0;
        }
        return min(a,b) + 1;
    }
};

//Solution No.2

class Solution {
public:
    int minDepth(TreeNode *root) {
        return helper(root, false);
    }

    int helper(TreeNode *root, bool hasBrother)
    {
        if(root == NULL) return hasBrother?INT_MAX:0;
        return min(helper(root->left, root->right != NULL), helper(root->right, root->left != NULL)) + 1;
    }

};
