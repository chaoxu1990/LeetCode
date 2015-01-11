/*

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


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
//My solution, O(N^2)
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(root == NULL) return true;
        if(checkLess(root, root->left) == false || checkGreater(root, root->right) == false) return false;

        return isValidBST(root->left) && isValidBST(root->right);
    }

    bool checkLess(TreeNode *root, TreeNode *check)
    {
        if(check == NULL) return true;
        if(check -> val >= root -> val) return false;
        return checkLess(root, check->left) && checkLess(root, check->right);
    }


    bool checkGreater(TreeNode *root, TreeNode *check)
    {
        if(check == NULL) return true;
        if(check -> val <= root -> val) return false;
        return checkGreater(root, check->left) && checkGreater(root, check->right);
    }
};

//Another better solution from Google, O(n)
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValid(root, INT_MIN, INT_MAX);
    }

    bool isValid(TreeNode *root, int left, int right)
    {
        if(root == NULL)return true;
        if(root->val == INT_MIN && root->left != NULL)return false;
        if(root->val == INT_MAX && root->right != NULL) return false;
        if(root->val > right || root->val < left) return false;

        return isValid(root->left, left, root->val - 1) && isValid(root->right, root->val + 1, right);
    }
};
