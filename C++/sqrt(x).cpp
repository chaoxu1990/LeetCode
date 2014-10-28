/*

Implement int sqrt(int x).

Compute and return the square root of x.

*/


class Solution {
public:
    int sqrt(int x) {
        int l = 1, r = x/2, m = 0, tmp_m = 0;

        if(x<2) return x;

        while(l<=r)
        {
            m = l + (r-l)/2;
            if(x/m > m)
            {
                l = m + 1;
                tmp_m = m;
            }
            else if(x/m < m)
                r = m - 1;
            else
                return m;
        }
        return tmp_m;
    }
};
