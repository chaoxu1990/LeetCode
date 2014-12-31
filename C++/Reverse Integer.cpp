/*

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).

*/

class Solution {
public:
    int reverse(int x) {
        int sign = 0;
        if(x<0) sign = -1;
        else if(x>0) sign = 1;
        else return 0;

        int result = 0, tmp = 0;
        x = abs(x);
        while(x)
        {
            tmp = x%10;
            result = result * 10 + tmp;
            x /= 10;
        }

        return result * sign;
    }
};


//Adding overflow detect
class Solution {
public:
    int reverse(int x) {
        long long int result = 0;
        bool positive = true;
        if(x<0) positive = false;
        
        x = abs(x);
        while(x)
        {
            int digit = x%10;
            result = result*10 + digit;
            x /= 10;
        }
        
        if(positive == false) result *= -1;
        if(result<INT_MIN || result > INT_MAX) result = 0;
        return result;
    }
};
