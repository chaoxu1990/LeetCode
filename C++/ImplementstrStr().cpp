/*

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if
needle is not part of haystack.

*/

//solution 1: brute force
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
     int hLen = strlen(haystack), nLen = strlen(needle);

     int i = 0, j = 0;

     while(i<hLen&&j<nLen)
     {
         if(haystack[i] == needle[j])
         {
             i++;
             j++;
         }
         else
         {
             i = i - j + 1;
             j = 0;
         }
     }
     if(j==nLen)
        return haystack + i - j;
    else
        return nullptr;
    }
};


//solution 2: KMP algorithm


class Solution {
public:
    void GetNextval(char *p, int next[])
    {
        int i = -1, j = 0, len = strlen(p);
        next[0] = i;

        while(j<len-1)
        {
            if(i==-1 || p[i] == p[j])
            {
                i++;
                j++;
                if(p[i]==p[j])
                    next[j] = next[i];
                else
                    next[j] = i;
            }
            else
                i = next[i];
        }

    }
    char *strStr(char *haystack, char *needle) {
     int hLen = strlen(haystack), nLen = strlen(needle);
     int i = 0, j = 0;
     int *next = (int*)malloc(sizeof(int)*nLen);
     GetNextval(needle, next);

     while(i<hLen&&j<nLen)
     {
         if(j == -1 || haystack[i] == needle[j])
         {
             i++;
             j++;
         }
         else
         {
             j = next[j];
         }
     }
     if(j==nLen)
        return haystack + i - j;
    else
        return nullptr;
    }
};


//solution 3:
//opensource from:
//http://www.opensource.apple.com/source/xnu/xnu-792.13.8/libsa/strstr.c
//actually, it's still brute force.

class Solution {
public:

    char *strStr(char *in, char *str) {
    char c;
    size_t len;

    c = *str++;
    if (!c)
        return (char *) in;	// Trivial empty string case

    len = strlen(str);
    do {
        char sc;

        do {
            sc = *in++;
            if (!sc)
                return (char *) 0;
        } while (sc != c);
    } while (strncmp(in, str, len) != 0);

    return (char *) (in - 1);
}
};
