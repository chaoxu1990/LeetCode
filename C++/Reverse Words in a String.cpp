/*

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

*/

class Solution {
public:
    void reverseString(string &s, const int begin, const int end)
    {
        int i = begin, j = end-1;
        while(i<j)
        {
            char tmp = s[i];
            s[i++] = s[j];
            s[j--] = tmp;
        }
    }
    void reverseWords(string &s) {

         int b = 0, e = s.size() - 1;

        while(s[b] == ' ') b++;
        while(s[e] == ' ') e--;

        s.erase(s.begin(), s.begin() + b);
        if(s.empty()) return;
        s.erase(s.begin() + e - b + 1, s.end());

        if(s.size() < 2) return;

        for(int i = 0; i<s.size()-1; i++)
        {
            if(s[i] == ' ' && s[i+1] == ' ')
            s.erase(s.begin()+i--);
        }

        reverseString(s, 0, s.size());

        int begin = 0, end = 0, tmp = s.size() - 1;

        for(size_t i = 0; i<s.size(); i++)
        {
            if(s[i] == ' ')
            {
                reverseString(s, begin, i);
                begin =  i + 1;
            }
        }
        reverseString(s, begin, s.size());
    }
};
