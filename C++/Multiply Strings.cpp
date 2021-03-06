/*

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

*/

class Solution {
public:
    string multiply(string num1, string num2) {
        size_t len1 = num1.length(), len2 = num2.length();
        size_t len3 = len1 + len2;
        string result(len3, '0');

        for(int i = len1 - 1; i>=0; --i)
        {
            for(int j = len2 - 1; j>=0; --j)
            {
                int tmp_num = (num1[i]-'0')*(num2[j]-'0');
                int cur_value = result[i+j+1] - '0' + tmp_num;
                result[i+j+1] = cur_value % 10 + '0';
                result[i+j] = result[i+j] - '0' + cur_value/10 + '0';
            }
        }

       size_t pos = result.find_first_not_of('0');
       if(pos != string::npos)
            result = result.substr(pos);
       else
            result = "0";

        return result;
    }
};


//Jan 5th update code. More concise, 19ms passed:

class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size()+num2.size(), '0');
        
        for(int i = num1.size() - 1; i>=0; i--)
        {
            for(int j = num2.size() - 1; j>=0; j--)
            {
                int tmp = result[i+j+1] - '0' + (num1[i]-'0')*(num2[j]-'0');
                result[i+j+1] = tmp%10 + '0';
                result[i+j] += tmp/10;
            }
        }
        size_t start = result.find_first_not_of('0');
        return start!=string::npos?result.substr(start):"0";
    }
};