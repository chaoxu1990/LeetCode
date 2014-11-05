/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    bool isBalanced(TreeNode *root) {

        if(root == NULL) return true;

        int a = levelCount(root->left);
        int b = levelCount(root->right);

        if(a==-1 || b == -1 || abs(a-b) > 1) return false;

     return true;
    }


    int levelCount(TreeNode *root)
    {
        if(root == NULL) return 0;

        int a = levelCount(root->left) + 1;
        int b = levelCount(root->right) + 1;
        if(abs(a-b)>1 || a==0 || b==0) return -1;

        return a>b?a:b;
    }
};
