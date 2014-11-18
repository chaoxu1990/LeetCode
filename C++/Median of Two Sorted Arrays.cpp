/*

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

*/


class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int size = m+n;
        if(size % 2 == 1)
        return helper(A, m, B, n, size/2 + 1);
        else
        return (helper(A,m,B,n,size/2) + helper(A,m,B,n,size/2+1))/2;
    }
    double helper(int A[], int Asize, int B[], int Bsize, int index)
    {
        if(Asize>Bsize) return helper(B,Bsize,A, Asize, index);
        if(Asize == 0) return B[index-1];
        if(index == 1) return min(A[0],B[0]);

        int idxA = min(index/2, Asize);
        int idxB = index - idxA;

        if(A[idxA - 1] < B[idxB - 1])
            return helper(A+idxA, Asize-idxA, B, Bsize, index-idxA);
        else if(A[idxA - 1] > B[idxB - 1])
            return helper(A, Asize, B+idxB, Bsize-idxB, index-idxB);
        else
            return A[idxA - 1];
    }
};
