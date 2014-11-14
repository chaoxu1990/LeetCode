/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

*/
//Solution No.1: Using recursion;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        if(l1!=l2) return false;
        if(l1 == 1) return s1[0] == s2[0];

        string tmp_s1 = s1, tmp_s2 = s2;
        sort(tmp_s1.begin(), tmp_s1.end());
        sort(tmp_s2.begin(), tmp_s2.end());
        for(int i = 0; i<l1; ++i)
            if(tmp_s1[i] != tmp_s2[i]) return false;

        bool result = false;
        for(int i=1; i<l1 && result == false; ++i)
        {
            string s1_left = s1.substr(0,i);
            string s1_right = s1.substr(i);
            string s2_left = s2.substr(0,i);
            string s2_right = s2.substr(i);
            string s3_left = s2.substr(0, l1-i);
            string s3_right = s2.substr(l1-i);

            result = (isScramble(s1_left, s2_left) && isScramble(s1_right, s2_right))
                   ||(isScramble(s1_left, s2_right) && isScramble(s1_right, s2_left))
                   || (isScramble(s1_left, s3_left) && isScramble(s1_right, s3_right))
                   ||(isScramble(s1_left, s3_right) && isScramble(s1_right, s3_left));
        }

        return result;
    }
};

//Solution No2: Using DP;（真心看不懂，如果面到了就是只能跪了）
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        bool table[l1+1][l1][l1];
        fill_n(&table[0][0][0], (l1+1)*l1*l1, false);
        table[0][0][0] = true;
        for(int i = 0; i<l1; ++i)
            for(int j = 0; j<l1; ++j)
                table[1][i][j] = s1[i] == s2[j];

        for(int i = 1; i<l1+1; ++i)
        {
            for(int j = 0; j + i<=l1; ++j)
            {
                for(int k = 0; k + i<=l1; ++k)
                {
                    for(int l = 1; l<i; l++)
                    {
                        if((table[l][j][k] && table[i-l][j+l][k+l])
                         ||(table[i-l][j+l][k] && table[l][j][k+i-l]))
                         {
                             table[i][j][k] = true;
                             break;
                         }
                    }
                }
            }
        }

        return table[l1][0][0];
    }
};
