/*

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        string seq(n,0);
        int fac = 1;
        for(int i = 0; i<n; ++i)
        {
            seq[i] = i+1;
            fac *= i+1;
        }

        k--;

        for(int i = 0; i<n; ++i)
        {
            fac = fac/(n-i);
            int choosed = k/fac;
            result.push_back(seq[choosed] + '0');
            seq.erase(seq.begin() + choosed);
            k %= fac;
        }


        return result;
    }
};
