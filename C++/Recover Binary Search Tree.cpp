/*

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

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
    TreeNode *first;
    TreeNode *second;
    TreeNode *pre;

    void inorder(TreeNode *root)
    {
        if(!root) return;
        inorder(root->left);
        if(!pre) pre = root;
        else{
        if(pre->val > root->val){
            if(!first) first = pre;
            second = root;
        }
        pre = root;
        }
        inorder(root->right);
    }

    void recoverTree(TreeNode *root) {
        pre = NULL;
        first = NULL;
        second = NULL;

        inorder(root);

        swap(first->val, second->val);
    }
};
