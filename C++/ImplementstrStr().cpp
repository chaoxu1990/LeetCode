/*

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if
needle is not part of haystack.

*/


class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        char *p = haystack, *q = needle;
        int cnt = 0;
        while(*q != '\0')
        {
            cnt++;
            q++;
        }
        q = needle;
        while(*p != '\0' && *q != '\0')
        {
            if(*p == *q)
            {
                p++;
                q++;
            }
            else
            {
                if(q == needle)
                    p++;
                else
                {
                    p = p - (q-needle) + 1;
                }
                q = needle;
            }
        }
        if(*q == '\0')
            return p-(q-needle);
        else
            return nullptr;
    }
};
