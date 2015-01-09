/*

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

*/

//Same code with Search in Rotated Sorted Array.cpp
class Solution {
public:
    bool search(int A[], int n, int target) {
        int l = 0, r = n-1, piv = 0, mid = 0;

        if(A[l]<A[r]){piv = 0;}
        else{
            while(l<mid)
            {
                if(A[r]<A[mid]) l = mid;
                if(A[l]>A[mid]) r = mid;
                mid = l + (r-l)/2;
            }
            piv = l + 1;
        }
        l = piv; r = piv + n - 1;
		
        while(true)
        {
            mid = l + (r - l)/2;

            if(A[mid%n] > target) r = mid - 1;
            if(A[mid%n] < target) l = mid + 1;
            if(A[mid%n] == target) return true;
            if(l > r) break;
        }
        return false;
    }
};
