/*

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

//Same code with Search in Rotated Sorted Array II.cpp
class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, r = n-1, piv = 0, mid = 0;

        for(int i = 0; i<n-1; ++i)
            if(A[i]>A[i+1]) piv = i+1;
        if(piv == 0)
        {
            l = 0; r = n - 1;
        }
        else
        {
            l = piv; r = piv + n - 1;
        }
        while(true)
        {
            mid = l + (r - l)/2;

            if(A[mid%n] > target) r = mid - 1;
            if(A[mid%n] < target) l = mid + 1;
            if(A[mid%n] == target) return mid%n;
            if(l >r) break;
        }
        return -1;
    }
};
