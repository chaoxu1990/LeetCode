/*

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

*/

class Solution {
public:
    void reverse(string &s, int start, int end)
    {
        while(start < end)
            swap(s[start++], s[end--]);
    }
    void reverseWords(string &s) {
        int start = 0, end = s.size() - 1;
        while(start <= end)
        {
            if(s[start] == ' ') start++;
            else if(s[end] == ' ') end--;
            else break;
        }
        s = s.substr(start, end - start + 1);
        
        reverse(s, 0, s.size() - 1);
        
        for(int i = 0; i<s.size(); i++)
        {
            int j = s.find_first_of(' ', i);
            if(j == -1) j = s.size();
            reverse(s, i, j-1);
            int k = s.find_first_not_of(' ', j);
            if(k > j + 1)
                s.erase(j+1, k-j-1);
            i = j;
        }
    }
};