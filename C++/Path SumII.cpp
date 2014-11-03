/*

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> parth;
        vector<vector<int>> result;
        helper(root, sum, parth, result);
        return result;
    }

    void helper(TreeNode *root, int sum, vector<int> &parth, vector<vector<int>> &result)
    {
        if(!root) return;
        parth.push_back(root->val);
        if(!root->left && !root->right)
        {
            int tmpSum = 0;
            for(int i = 0; i< parth.size(); ++i)
            {
                tmpSum+=parth[i];
            }
            if(tmpSum == sum) result.push_back(parth);
        }

        if(root->left) helper(root->left, sum, parth, result);
        if(root->right) helper(root->right, sum, parth, result);

        parth.pop_back();
        return;
    }

};
