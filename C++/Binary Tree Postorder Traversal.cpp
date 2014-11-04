/*

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
//Solution No.1 recursion, trivial
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode *root, vector<int>&result)
    {
        if(!root) return;
        helper(root->left, result);
        helper(root->right, result);
        result.push_back(root->val);

        return;

    }
};

//Solution No.2 iteration
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
       if(!root) return vector<int>();

       vector<int> result;
       stack<TreeNode*> s;
       TreeNode*p = root, *head = root;
       s.push(p);
       while(!s.empty())
       {
           p = s.top();
           if((!p->left && !p->right)||(p->left == head || p->right == head))
           {
               s.pop();
               result.push_back(p->val);
               head = p;
           }
           else
           {
               if(p->right) s.push(p->right);
               if(p->left) s.push(p->left);
           }
       }
       return result;
    }
};
