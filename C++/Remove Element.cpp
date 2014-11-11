/*

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n == 0 || A == NULL) return 0;
        for(int i = 0; i < n; ++i)
        {
            if(A[i] == elem)
            {
                while(n>0 && A[n-1] == elem) n--;
                if(n==0||i==n) break;
                else
                {
                    swap(A[i], A[n-1]);
                    n--;
                }
            }
        }
        return n;
    }
};
