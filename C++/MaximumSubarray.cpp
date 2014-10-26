/*

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int local = A[0], global = A[0];
        for(size_t i = 1; i<n; i++)
        {
            local = max(local+A[i], A[i]);
            global = max(local, global);
        }

        return global;
    }
};
