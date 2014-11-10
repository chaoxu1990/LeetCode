/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int right_index = 0, left_index = -1;
        int n = num.size();

        for(int i = n-1; i>0; --i)
        {
            if(num[i-1]<num[i])
            {
                left_index = i-1;
                break;
            }
        }

        if(left_index == -1)
        {
            sort(num.begin(), num.end());
            return;
        }

        for(int i = n-1; i>0; --i)
        {
            if(num[i]>num[left_index])
            {
                right_index = i;
                break;
            }
        }

        swap(num[left_index], num[right_index]);

        reverse(num.begin() + left_index + 1, num.end());
    }
};
