/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

class Solution {
public:
    static bool cmp(int num1, int num2)
    {
        string tmp1, tmp2;
        tmp1 = to_string(num1)+to_string(num2);
        tmp2 = to_string(num2)+to_string(num1);
        if(tmp1 <= tmp2) 
            return false;
        else 
            return true;
        
    }
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), cmp);
        if(num[0] == 0) return "0";
        string ret;
        for(auto i: num)
            ret.append(to_string(i));
        return ret;
    }
};
