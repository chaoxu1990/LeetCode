/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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


//Solution No.1 recursion.
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return root?isSymmetric(root->left, root->right):true;
    }
    bool isSymmetric(TreeNode *left, TreeNode *right)
    {
        if(!left&&!right) return true;
        if(!left||!right) return false;

        return left->val==right->val
            && isSymmetric(left->left, right->right)
            && isSymmetric(left->right, right->left);
    }
};


//Solution No.2: iteration.
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        stack<TreeNode*> treeStack;
        treeStack.push(root->left);
        treeStack.push(root->right);

        while(!treeStack.empty())
        {
            TreeNode *left = treeStack.top();
            treeStack.pop();
            TreeNode *right = treeStack.top();
            treeStack.pop();

            if(!left&&!right) continue;
            if(!left||!right) return false;
            if(left->val != right->val) return false;

            treeStack.push(left->left);
            treeStack.push(right->right);

            treeStack.push(left->right);
            treeStack.push(right->left);
        }

        return true;
    }
};
