/*

Given preorder and inorder traversal of a tree, construct the binary tree.


*/

//这么简单的题目居然刷了俩小时，太失败:(
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(!preorder.size()) return NULL;
        return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int Prel, int Prer, int Inl, int Inr)
    {
        if(Inl > Inr || Prel > Prer) return NULL;
        if(Inl == Inr && Prel == Prer)
        {
            TreeNode *root = new TreeNode(inorder[Inl]);
            return root;
        }
        int cnt = Inl;

        while(inorder[cnt] != preorder[Prel]) cnt++;
        TreeNode *root = new TreeNode(inorder[cnt]);

        int numLeft = cnt - Inl;
        root->left = buildTree(preorder, inorder, Prel + 1, Prel + numLeft, Inl, cnt-1);
        root->right = buildTree(preorder, inorder, Prel + numLeft + 1, Prer, cnt + 1, Inr);
        return root;
    }


};
