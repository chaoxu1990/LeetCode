class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while(n-->0)
        {
            int i = n%26;
            n /= 26;
            ret = (char)(i +'A') + ret;
        }
        return ret;

    }
};
