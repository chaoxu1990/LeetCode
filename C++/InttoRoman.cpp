/*

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

*/

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
       const int ratioInt[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
       const string ratio[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        for(int i = 0; num > 0; i++)
        {
            int cnt = num/ratioInt[i];
            num %= ratioInt[i];

            for(;cnt > 0; cnt--)
                result += ratio[i];
        }
        return result;
    }
};
