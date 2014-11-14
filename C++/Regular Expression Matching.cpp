/*

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

总的来说思路是递归。
判断下一个字符是否是*：
如果不是*，则判断当前字符是否匹配。
如果是*，则因为不能确定*到底会匹配几个，在当前字符匹配的前提下，要枚举所有的情况，从假设匹配0个，1个，2个。。。只要有一种情况成功了，最终也就成功了。
我们可以从0开始，先考虑直接跳过当前2个正则字符，然后再1个，2个继续搜索下去。
如果是*，但是当前字符不匹配，则跳过两个递归。
具体的代码如下，注释写得很清楚。

*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0') return *s == '\0';
        if(*(p+1) != '*')
        {
            if((*s != '\0' && *p == '.') || *p == *s)
            {
                return isMatch(s+1, p+1);
            }
            else
                return false;
        }
        else
        {
            while((*p == '.' && *s != '\0') || *p == *s)
            {
                if(isMatch(s, p+2))
                    return true;
                s++;
            }

            return isMatch(s, p+2);
        }

    }
};
