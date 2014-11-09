/*

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {

        if(n < 2) return n;
        int result = 0, tmp = A[0], tmpcnt = 0;

        for(int i = 0; i<n; i++)
        {
            if(A[i] == tmp && tmpcnt < 2)
            {
                A[result] = A[i];
                tmpcnt++;
                result++;
            }
            else if(A[i] != tmp)
            {
                A[result] = A[i];
                tmp = A[i];
                result++;
                tmpcnt = 1;
            }
        }
        return result;
    }
};
