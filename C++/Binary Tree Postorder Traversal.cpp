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

//Solution No.3 Morris traversal with constant space and O(n) time.
class Solution {
public:
    vector<int> result;
    void reverse(TreeNode * from, TreeNode *to)
    {
        if(from == to) return;
        TreeNode *x = from, *y = from->right, *z = NULL;

        while(x != to)
        {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
        }
    }
    void print(TreeNode *from, TreeNode *to)
    {
        reverse(from, to);
        TreeNode *p = to;
        while(true)
        {
            result.push_back(p->val);
            if(p == from) break;
            p = p->right;
        }
        reverse(to, from);
    }
    vector<int> postorderTraversal(TreeNode *root) {

        TreeNode *cur = new TreeNode(-1), *pre = NULL;
        cur->left = root;

        while(cur != NULL)
        {
            if(cur->left == NULL)
                cur = cur->right;

            else
            {
                pre = cur -> left;
                while(pre->right != NULL && pre->right != cur)
                    pre = pre->right;
                if(pre->right == NULL)
                {
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    print(cur->left, pre);
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
