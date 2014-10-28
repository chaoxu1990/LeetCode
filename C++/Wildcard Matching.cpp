/*

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false


solution from: http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html
*/


class Solution {
public:
    bool isMatch(const char *s, const char *p) {

        const char *star = NULL;
        const char *ss = s;
        while(*s)
        {
            if(*p=='?'|| *p == *s){p++;s++;continue;}
            if(*p == '*'){star = p++; ss = s; continue;}
            if(star){p = star + 1; s = ++ss; continue;}

            return false;
        }

        while(*p == '*') p++;
        return !*p;
    }
};
