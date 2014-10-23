/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

*/


class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size(); i<=j;)
        {
            if((s[i]<='Z'&&s[i]>='A')||(s[i]<='z'&&s[i]>='a')||(s[i]>='0'&&s[i]<='9'))
            {
                if((s[j]<='Z'&&s[j]>='A')||(s[j]<='z'&&s[j]>='a')||(s[j]>='0'&&s[j]<='9'))
                {
                    if((s[i]!=s[j])&&(s[i]!=s[j]-'a'+'A')&&(s[i]!=s[j]+'a'-'A'))
                    return false;
                    else
                    {
                        i++;
                        j--;
                        continue;
                    }
                }
                else
                {
                    j--;
                    continue;
                }
            }
            else
            {
                i++;
                continue;
            }
        }
        return true;
    }
};



//Another much clear solution with same logic:

class Solution {
public:
      bool isPalindrome(string s) {
          transform(s.begin(), s.end(), s.begin(), ::tolower);
          auto left = s.begin(), right = prev(s.end());
          while (left < right) {
              if (!::isalnum(*left))  ++left;
              else if (!::isalnum(*right)) --right;
              else if (*left != *right) return false;
          }
          return true;
      }
};

