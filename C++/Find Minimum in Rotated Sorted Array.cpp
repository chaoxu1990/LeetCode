/*

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

*/

//solution No.1: O(n)

class Solution {
public:
    int findMin(vector<int> &num) {
        int min = num[0];
        for(size_t i = 1; i<num.size(); ++i)
        {
            if(min>num[i])
                min = num[i];
        }

        return min;
    }
};


//solution No.2: O(log(n))
class Solution {
public:
    int findMin(vector<int> &num) {
        int min = num[0], left = 0, right = num.size()-1, mid = 0;
        if(num[left]<num[right]) return num[left];

        while(left<right-1)
        {
            mid = left + ((right-left)>>1);
            if(num[mid] < num[left])
                right = mid;
            else if(num[mid] > num[right])
                left = mid;
        }

       min = num[left]<num[right]?num[left]:num[right];

        return min;
    }
};
