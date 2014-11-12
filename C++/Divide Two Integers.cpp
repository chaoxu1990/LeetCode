/*

Divide two integers without using multiplication, division and mod operator.

*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0 || divisor == 1) return dividend;
        int sign = 1;
        int result = 0, cnt = 1;
        if(dividend<0) sign = -sign;
        if(divisor<0) sign = -sign;

        long long int tmpdd = abs((long long)dividend);
        long long int tmpdr = abs((long long)divisor);
        unsigned long long int dr = abs((long long)divisor);

        if(tmpdd < tmpdr) return 0;


        while(tmpdd >= dr)
        {
            while(tmpdd > (tmpdr << 1))
            {
                tmpdr = tmpdr << 1;
                cnt = cnt << 1;
            }
            result += cnt;
            tmpdd -= tmpdr;

            while(tmpdd < tmpdr)
            {
                tmpdr = tmpdr >> 1;
                cnt = cnt >> 1;
            }

        }
        return sign>0?result:-result;
    }
};
