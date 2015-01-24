/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        findNext(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return st.empty() == false;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *ret = st.top();
        st.pop();
        if(ret->right)
            findNext(ret->right);
        return ret->val;
    }

private:
    stack<TreeNode *> st;
    void findNext(TreeNode *root)
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
