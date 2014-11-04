/*

Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(!postorder.size()||!inorder.size()) return NULL;

        return buildTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int inL, int inR, int postL, int postR)
    {
        if(inL>inR || postL > postR) return NULL;

        TreeNode *root = new TreeNode(postorder[postR]);

        if(inL == inR && postL == postR) return root;
        int cnt = inR;
        while(inorder[cnt] != postorder[postR]) cnt--;

        int numLeft = inR - cnt;

        root->left = buildTree(inorder, postorder, inL, cnt - 1, postL, postR-numLeft-1);
        root->right = buildTree(inorder, postorder, cnt + 1, inR, postR-numLeft, postR - 1);

        return root;

    }

};
