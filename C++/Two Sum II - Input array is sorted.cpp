/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        map<int, int> table;
        for(int i = 0; i<numbers.size(); i++)
        {
            if(table.find(target-numbers[i]) != table.end())
            {
                ret.push_back(min(i+1, table[target-numbers[i]]));
                ret.push_back(max(i+1, table[target-numbers[i]]));
            }
            else
                table[numbers[i]] = i+1;
        }
        
        return ret;
    }
};
