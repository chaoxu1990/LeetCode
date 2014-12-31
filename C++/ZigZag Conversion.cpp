/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

class Solution {
public:
    string convert(string s, int nRows) {
        vector<string> result;
        int cnt = 0;
        for(int i = 0; i<nRows; ++i)
        {
            result.push_back("");
        }

        for(int i = 0; i<s.size();)
        {
            result[cnt++] += s[i++];
            if(cnt == nRows)
            {
                cnt-=2;
                if(cnt<0) cnt = 0;
                while(cnt > 0 && i<s.size())
                {
                    for(int r = 0; r<nRows && i<s.size(); r++ )
                    {
                        if(r==cnt)
                            result[cnt--] += s[i++];
                    }
                }
            }
        }
        string output;
        for(size_t i = 0; i<result.size(); ++i)
        {
            for(size_t j = 0; j<result[i].size(); ++j)
            {
                output += result[i][j];
            }
        }
        return output;
    }
};


//Another better mathematical Solution:
class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows <= 1) return s;
        string result;
        int zigsize = nRows*2 - 2;
        for(int i = 0; i<nRows; ++i)
        {
            for(int j = i; j<s.length(); j += zigsize)
            {
                if(j>=s.length()) break;
                result += s[j];          
                if(i>0 && i<nRows - 1)
                {
                   int idx = j + zigsize - 2*i;
                   if(idx < s.length())
                        result += s[idx];
                }
            }
        }
        
        return result;
    }
};
