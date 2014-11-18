/*

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

*/

class Solution {
public:
    int findMin(vector<int> &num) {
       return helper(num, 0, num.size()-1);
    }

    int helper(vector<int> &num, int left, int right)
    {
        if(num[left] < num[right]) return num[left];
        while(left<right-1)
        {
            int mid = left + (right-left)/2;

            if(num[mid] > num[left])
                left = mid;
            else if(num[mid] < num[left])
                right = mid;
            else return min(helper(num, left, mid), helper(num, mid, right));

        }
        return num[left]>=num[right]?num[right]:num[left];

    }
};
