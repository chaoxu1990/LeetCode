/*

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/

/*
 * ones for the bits appear in first time.
 * twos for the bits appear second time.
 * threes for the bits appear in third time.
 * clear bits appear in threes from ones and twos.
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        for(int i = 0; i<n; ++i)
        {
            twos |= ones & A[i];
            ones ^= A[i];
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }

        return ones;
    }
};
