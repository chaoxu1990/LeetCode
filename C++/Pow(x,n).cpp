/*

Implement pow(x, n).

*/

class Solution {
public:
    double pow(double x, int n) {
        double result = 1;
        int m = n;
        for(;n;x*=x, n/=2) if(n%2) result *= x;

        return m>=0?result:1/result;
    }
};
