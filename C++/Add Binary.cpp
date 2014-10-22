/*

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/


class Solution {
public:
    string addBinary(string a, string b) {
        size_t l = a.size()>b.size()?a.size():b.size();
        int carry = 0, sum = 0;
        string result = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(size_t i = 0; i < l; i++)
        {
            const int ip1 = i<a.size()?a[i]-'0':0;
            const int ip2 = i<b.size()?b[i]-'0':0;
            const int num = ip1 + ip2 + carry;

            sum = num % 2;
            carry = num / 2;

            result.insert(result.begin(), sum + '0');
        }
        if(carry) result.insert(result.begin(),'1');
        return result;

    }
};
