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
//Solution No.1: using recursion, not actually constant space.
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

//Solution No.2: using Morris iteration, constant space.

class Solution {
public:
    TreeNode *first;
    TreeNode *second;

    void inorder(TreeNode *root)
    {
       TreeNode* cur = root, *pre = NULL;
       while(cur != NULL)
       {
           if(cur->left == NULL)
           {
               detect(pre,cur);
               pre = cur;
               cur = cur->right;
           }
           else
           {
               TreeNode *tmp = cur->left;
               while(tmp->right != NULL && tmp->right != cur)
                    tmp = tmp->right;
               if(tmp->right == NULL)
               {
                   tmp->right = cur;
                   cur = cur->left;
               }
               else
               {
                   detect(pre, cur);
                   tmp->right = NULL;
                   pre = cur;
                   cur = cur->right;
               }
           }
       }
    }

    void detect(TreeNode *pre, TreeNode *cur)
    {
        if(pre != NULL && pre->val > cur->val)
        {
            if(first == NULL){first = pre;}
            second = cur;
        }
    }

    void recoverTree(TreeNode *root) {
        first = NULL;
        second = NULL;

        inorder(root);

        swap(first->val, second->val);
    }
};
