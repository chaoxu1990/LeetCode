/*

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/



//solution No.1 DP O(n^2) with n+1 vector.
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1,0);
        f[0] = 1;
        f[1] = 1;
        int tmp = 0;
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 1; j <= i; ++j)
            {
                    f[i] += f[j-1]*f[i-j];
            }
       }
        return f[n];
    }
};

//solution No.2: Recursive
class Solution {
public:
    int numTrees(int n) {
        return helper(1,n);
    }

    int helper(int left, int right)
    {
        if(left>=right) return 1;

        int result = 0;

        for(int i = left; i <= right; ++i)
        {
            result += helper(left, i-1)*helper(i+1, right);
        }

        return result;
    }
};
