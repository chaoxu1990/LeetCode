/*

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

*/


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode *fakedHead = new TreeLinkNode(-1);

        for(TreeLinkNode *prev = fakedHead, *p = root; p; p = p->next)
        {
            if(p->left)
            {
                prev->next = p->left;
                prev = prev->next;
            }
            if(p->right)
            {
                prev->next = p->right;
                prev = prev->next;
            }
        }
        connect(fakedHead->next);
    }
};
