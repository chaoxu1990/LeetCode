/*

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;
        for(int i = digits.size() - 1; i>=0; --i)
        {
            if(carry == true)
            {
                digits[i] += 1;
                if(digits[i] == 10)
                {
                    digits[i] = 0;
                }
                else carry = false;
            }
        }

        if(carry == true)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};
