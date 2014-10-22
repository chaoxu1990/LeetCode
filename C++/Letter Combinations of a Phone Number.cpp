/*

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

//solution No.1

class Solution {
public:
    const vector<string> key = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        //if(digits.size() == 0) return result;
        helper(digits, 0, "", result);

        return result;
    }

    void helper(string &digits, int pos, string res, vector<string> &result)
    {
        if(pos == digits.size())
        {
            result.push_back(res);
            return;
        }
        for(auto c: key[digits[pos]-'0'])
        {
            helper(digits, pos+1, res+c, result);
        }
    }
};


//solution No.2 iteration should also be possible by using stack



