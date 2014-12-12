/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int result = num[0] + num[1] + num[2];
        for(int i = 0; i<num.size() - 2; i++)
        {
            if(i > 0 && num[i] == num[i-1]) continue;
            for(int j = i+1, k = num.size() - 1; j<k;)
            {
                if(j > i+1 && num[j] == num[j-1]) {j++; continue;}
                int sum = num[i] + num[j] + num[k];
                if(abs(sum - target) < abs(result - target))
                    result = sum;
                
                if(sum == target)
                {
                    return sum;
                }
                else if(sum > target)
                {
                    while(k > j + 1 && num[k-1] == num[k]) k--;
                    k--;
                }
                else
                    j++;
            }
        }
        return result;
    }
};