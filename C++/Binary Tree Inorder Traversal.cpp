/*

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

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

//Solution No.1: recursion, trivial, try iteration.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;

        helper(root, result);
        return result;
    }

    void helper(TreeNode *root, vector<int>&result)
    {
        if(!root) return;
        helper(root->left, result);
        result.push_back(root->val);
        helper(root->right, result);
        return;
    }

};

//Solution No.2: iteration

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        if(!root) return vector<int>();

        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *p;

        p = root;
        while(!s.empty()||p)
        {
            if(p)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }
};
