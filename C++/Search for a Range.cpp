/*

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/


//First solution, it's actually O(n) soulution.
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l = 0, r = n - 1, mid = 0;
        vector<int> result(2,-1);
        bool found = false;
        while(l<=r)
        {
            mid = l + (r-l)/2;
            if(A[mid]<target) l = mid + 1;
            if(A[mid]>target) r = mid - 1;
            if(A[mid]==target)
            {
                found = true;
                break;
            }
        }

        if(found)
        {
            int start = mid, end = mid;
            while(start>0 && A[start-1] == A[mid]) start--;
            while(end<n-1 && A[end+1] == A[mid]) end++;
            result[0] = start;
            result[1] = end;
        }

        return result;
    }
};

//Second solution: do binary search for left and right bound. It's O(log(n)) in average and also worst case
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l = 0, r = n-1;
        int m = l + (r-l)/2;
        bool found = false;
        vector<int> result;
        //Search for the left bound
        while(l<m)
        {
            if(target < A[m]) r = m;
            else if(target > A[m]) l = m;
            else if(target == A[m])
            {
                r = m;
            }
            m = l + (r-l)/2;
        }
        if(A[l] == target)
            result.push_back(l);
        else if(A[r] == target)
            result.push_back(r);
        else
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        
        l = 0; r = n-1; m = (r-l)/2 + l;
        //search for the right bound
        
        while(l<m)
        {
            if(target < A[m]) r = m;
            else if(target > A[m]) l = m;
            else if(target == A[m]) l = m;
            m = l + (r-l)/2;
        }
        if(A[r] == target)
            result.push_back(r);
        else 
            result.push_back(m);
            
     return result;   
    }
};
