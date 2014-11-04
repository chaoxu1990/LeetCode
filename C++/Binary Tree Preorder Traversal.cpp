/*

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

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

//Solution  No.1: recursion, trivial, try iteration.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;

        helper(root, result);
        return result;
    }

    void helper(TreeNode *root, vector<int>&result)
    {
        if(!root) return;
        result.push_back(root->val);
        helper(root->left, result);
        helper(root->right, result);
        return;
    }
};

//Solution 2: iteration, O(n) time and space.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if(!root) return vector<int>();
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        s.push(cur);

        while(!s.empty())
        {
            cur = s.top();
            s.pop();
            result.push_back(cur->val);

            if(cur->right) s.push(cur->right);
            if(cur->left) s.push(cur->left);
        }
     return result;
    }
};

//Solution 3: there should be iteration with O(1) space and O(n) time.
