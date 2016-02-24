/*

Given a string, find the length of the longest substring without repeating
characters. For example, the longest substring without repeating letters
for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest
substring is "b", with the length of 1.

*/


public class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> helper = new HashSet<Character>();
        int result = 0, p1 = 0, p2 = 0;
        while(p2 < s.length())
        {
            if(helper.contains(s.charAt(p2)))
            {
                result = Math.max(p2-p1, result);
                while(s.charAt(p2) != s.charAt(p1++))
                    helper.remove(s.charAt(p1-1));
            }
            else
                helper.add(s.charAt(p2));
            p2++;
        }
        return Math.max(p2-p1, result);
    }
}