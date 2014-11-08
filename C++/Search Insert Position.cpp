/*

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

//two versions of binary search
//No.1
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(A[n-1] < target) return n;
        if(A[0] > target) return 0;

        int l = 0, r = n-1, mid = 0;
        while(true)
        {
            mid = l + (r-l)/2;
            if(A[mid] < target) l = mid + 1;
            if(A[mid] > target) r = mid - 1;
            if(A[mid] == target) return mid;
            if(l>r) break;
        }

        return l;
    }
};

//No.2
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(A[n-1] < target) return n;
        if(A[0] > target) return 0;

        int l = 0, r = n-1, mid = 0;
        while(1)
        {
            mid = l + (r-l)/2;
            if(mid == l) break;
            if(A[mid] < target) l = mid;
            if(A[mid] > target) r = mid;
            if(A[mid] == target) return mid;
        }

        return A[mid]==target? mid: mid+1;
    }
};
