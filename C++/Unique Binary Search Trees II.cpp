/*

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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
    vector<TreeNode *> generateTrees(int n) {
       return generate(1,n);
    }

    vector<TreeNode *> generate(int left, int right)
    {
        vector<TreeNode *> substr;
        if(left > right)
        {
            substr.push_back(NULL);
            return substr;
        }

        for(int i = left; i <= right; ++i)
        {
            vector<TreeNode*> sl = generate(left, i-1), sr = generate(i+1, right);
            for(auto j: sl)
                for(auto k: sr)
                {
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = j;
                    tmp->right = k;
                    substr.push_back(tmp);
                }
        }
        return substr;
    }
};
