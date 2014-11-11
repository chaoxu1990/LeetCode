/*

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

*/
class Solution {
public:
    int atoi(const char *str) {
        if(str == NULL) return 0;

        bool positive = true, hasSign = false, overload = false;
        int index = 0;//, result = 0, old_result = INT_MIN;
        long long int result = 0;
        while(str[index] == ' ') index++;

        if(str[index] == '+'){positive = true; hasSign = true;}
        else if(str[index] == '-') {positive = false; hasSign = true;}
        else if(str[index] < '0' || str[index] > '9') return 0;

        if(hasSign == true && (str[index + 1] < '0' || str[index + 1] > '9')) return 0;
        for(int i = index;str[i] != '\0';++i)
        {
            if(hasSign == true){hasSign = false; continue;}

            if(str[i] < '0' || str[i] > '9') break;

            result = result*10 + str[i] - '0';

            if(result > INT_MAX) {overload = true; break;}

        }
        if(overload == true)
        {return positive?INT_MAX:INT_MIN;}
        else
        return positive?result:result*-1;
    }
};
