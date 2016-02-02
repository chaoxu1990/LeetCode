/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/


public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        Map<Integer, Integer> helper = new HashMap<Integer, Integer>();
        
        for(int i = 0; i<nums.length; i++)
            helper.put(target-nums[i], i+1);
        
        for(int i = 0; i<nums.length; i++)
        {
            Integer tmp = helper.get(nums[i]);
            if(tmp != null)
            {
                if(i+1 == tmp) continue;
                result[0] = Math.min(i+1, tmp);
                result[1] = Math.max(i+1, tmp);
                break;
            }
        }
        return result;
    }
}
