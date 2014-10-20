/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    int mapRomantoInt(const char c)
    {
        switch(c)
        {
            case 'M': return 1000;
            case 'D': return 500;
            case 'C': return 100;
            case 'L': return 50;
            case 'X': return 10;
            case 'V': return 5;
            case 'I': return 1;
        }
    }

public:
    int romanToInt(string s) {
        int result = 0;
        for(string::iterator it = s.begin(); it != s.end(); ++it)
        {
            if(it != s.end() && mapRomantoInt(*it) < mapRomantoInt(*(it+1)))
                result -= mapRomantoInt(*it);
            else
                result += mapRomantoInt(*it);
        }

        return result;

    }
};
