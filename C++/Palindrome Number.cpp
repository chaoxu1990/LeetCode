/*

Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

*/

class Solution {
public:
    bool isPalindrome(int x) {
     if(x<0) return false;
     if(x==0) return true;

     int len = 0, num = x;
     while(num)
     {
         num/=10;
         len++;
     }
     num = x;
     len--;
     while(len > 0)
     {

         if(num % 10 != (int)(num / pow(10, len)))
            return false;
        else
        {
            num = (num % (int)pow(10,len))/10;
            len -= 2;
        }
     }

     return true;
    }
};
