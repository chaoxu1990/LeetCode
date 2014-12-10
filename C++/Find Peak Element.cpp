/*

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.

*/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int l = 0, r = num.size() - 1;
        int mid = 0;

        while(l < r)
        {
            mid = l + (r-l)/2;

            if(mid - 1 > -1 && num[mid] < num[mid - 1])
            {
                r = mid - 1;
                continue;
            }
            else if(mid + 1 < num.size() && num[mid] < num[mid + 1])
            {
                l = mid + 1;
                continue;
            }
            else
                return mid;
        }

        return l;
    }
};
