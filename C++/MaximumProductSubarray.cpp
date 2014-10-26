/*

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

*/

class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n==0) return 0;
        if(n==1) return A[0];
        int max_local = A[0], min_local = A[0], global = A[0];
        for(size_t i = 1; i<n; ++i)
        {
            int copy = max_local;
            max_local = max(max(A[i], A[i]*max_local), min_local*A[i]);
            min_local = min(min(A[i], A[i]*copy), min_local*A[i]);
            global = max(max_local, global);
        }

        return global;
    }
};
