/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/

class Solution {
public:
    int trap(int A[], int n) {
        vector<int> left(n, A[0]);
        vector<int> right(n, A[n-1]);

        int max = 0;
        for(int i = 0; i<n; ++i)
        {
            if(max < A[i]) max = A[i];
            left[i] = max;
        }

        max = 0;
        int sum = 0;
        for(int i = n-1; i>=0; --i)
        {
            if(max < A[i]) max = A[i];
            right[i] = max;
            int tmp = min(left[i], right[i]) - A[i];
            if(tmp > 0) sum += tmp;
        }
        return sum;
    }
};
