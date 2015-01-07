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

//Another faster and more concise solution:

class Solution {
public:
    int sqrt(int x) {
        double old = 0, ne = 1;
        while((int)old != (int)ne)
        {
            old = ne;
            ne = (ne + x/ne)/2;
        }
        return (int)ne;
    }
};

//Some interesting story(if you can read Chinese) from: http://www.cnblogs.com/pkuoliver/archive/2010/10/06/1844725.html

//For some programmer who is more academical, here is a paper related to this piece of code
//http://www.matrix67.com/data/InvSqrt.pdf 

class Solution {
public:
    int sqrt(int number) {
    
    long i;
	float x2, y;
	const float threehalfs = 1.5F;
 
	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking（对浮点数的邪恶位级hack）
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?（这他妈的是怎么回事？）
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration （第一次牛顿迭代）
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed（第二次迭代，可以删除）
    
    int result = 1/y;
    if(result * result > number) return result-1;
    else return result;
    }
};
