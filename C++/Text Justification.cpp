/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.

*/

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        if(L == 0) return vector<string>(1,"");
        if(words.size() == 0)
        {
            string lastLine(L, ' ');
            result.push_back(lastLine);
            return result;
        }

        helper(words, 0, L, result);
        return result;
    }
    void padSpace(string &tmp, int num)
    {
        int extraSpace = num - tmp.size();
        string space(extraSpace, ' ');
        tmp += space;
    }
    void helper(vector<string> &words, int start, int L, vector<string> &result)
    {
        int spaceCount = 0;
        string tmp = "";
        tmp += words[0];
        for(int i = 0; i<words.size() - 1; ++i)
        {
            if(tmp.size() + words[i+1].size() >= L)
            {
                buildLine(tmp, spaceCount, L);
                result.push_back(tmp);
                tmp = words[i+1];
                spaceCount = 0;
                continue;
            }
            else
            {
                tmp = tmp + " " + words[i+1];
                spaceCount++;
            }
        }
        padSpace(tmp, L);
        result.push_back(tmp);
    }

    void buildLine(string &tmp, int spaceCount, int L)
    {
         if(spaceCount == 0)
        {
            padSpace(tmp, L);
            return;
        }
        int extraSpaceCount = L - tmp.size();
        int unEvenlySpace = extraSpaceCount % spaceCount;
        int basicSpace = extraSpaceCount / spaceCount;
        string sp(basicSpace, ' ');
        size_t found = tmp.find(' ');
        while(found != string::npos)
        {
            tmp.insert(found, sp);
            found = tmp.find(' ', found + sp.size() + 1);
        }
        found = 0;
        while(unEvenlySpace > 0)
        {
            found = tmp.find_first_of(' ', found+1);
            tmp.insert(found, 1, ' ');
            unEvenlySpace--;
            found = tmp.find_first_not_of(' ', found+1);
        }

    }
};
