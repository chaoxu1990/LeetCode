/*

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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

//Solution No.1, O(n^2):
class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root) return;
        if(root->left)
        {
            if(root->right)
            {
                TreeNode *tmp = root->left;
                while(tmp->right) tmp = tmp->right;
                tmp->right = root->right;
            }
            root->right = root->left;
            root->left = NULL;
        }

        flatten(root->right);

        return;
    }
};


//Solution No.2, O(n):

class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root) return;

        flatten(root, NULL);
        return;
    }

    TreeNode *flatten(TreeNode *root, TreeNode* tail)
    {
        if(NULL == root) return tail;

        root->right = flatten(root->left, flatten(root->right, tail));
        root->left = NULL;

        return root;
    }
};

//Solution No.3, O(n):

class Solution {
public:
    void flatten(TreeNode *root) {
       if(!root) return;

       stack<TreeNode *> s;
       s.push(root);
       while(!s.empty())
       {
           auto p = s.top();
           s.pop();
           if(p->right) s.push(p->right);
           if(p->left) s.push(p->left);

           if(!s.empty()) p->right = s.top();

           p->left = NULL;
       }
    }
};
