/*

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

*/

//Solution No.1:

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;

        int f1 = 1, f2 = 1, f3 = 1;
        for(int i = 1; i< s.size(); ++i)
        {
            if(s[i] == '0')
            {
                if(s[i-1] == '1' || s[i-1] == '2')
                    f3 = f1;
                else
                    return 0;
            }
            else if(s[i-1] == '1' || ((s[i-1] == '2') && (s[i] >= '0' && s[i]<= '6')))
                f3 = f1 + f2;
            else if(((s[i-1] != '2') && (s[i]>='1'&&s[i]<='9')) || (s[i-1] == '2' && (s[i]>='7'&&s[i]<='9')))
                f3 = f2;
            f1 = f2;
            f2 = f3;
        }
        return f2;
    }
};

//Solution No.2:

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;

        int f1 = 0, f2 = 1;
        for(int i = 1; i <= s.size(); ++i)
        {
            if(s[i-1] == '0') f2 = 0;

            if(i<2 || ! ((s[i-2] == '1') || (s[i-2] == '2' && s[i-1] <= '6'))) f1 = 0;

            int f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f2;
    }
};

