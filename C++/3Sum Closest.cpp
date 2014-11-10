/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());

        int result = 0;
        int old_result = INT_MAX;
        for(int i = 0;i<num.size();++i)
        {
            int j = i + 1, k = num.size()-1;
            while(j<k)
            {
                int sum = num[i]+num[j]+num[k];
                int new_result = abs(target - sum);
                if(new_result<old_result)
                {
                    result = sum;
                    old_result = new_result;
                }
                if(sum < target)
                    j++;
                else if(sum > target)
                    k--;
                else
                    return sum;
            }
        }

        return result;
    }
};
