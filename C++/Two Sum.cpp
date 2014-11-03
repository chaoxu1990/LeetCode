/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/


class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        unordered_map<int,int> helper;
        for(int i = 0; i<numbers.size(); ++i)
            helper[numbers[i]] = i;

        for(int i = 0; i<numbers.size(); ++i)
        {
            int gap = target-numbers[i];
            if(helper.find(gap) != helper.end())
            {
                if(helper[gap] == i) continue;
                result.push_back(i + 1);
                result.push_back(helper[gap] + 1);
                return result;
            }
        }
    }
};
