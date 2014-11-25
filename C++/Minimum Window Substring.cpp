/*

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

*/

class Solution {
public:
    string minWindow(string S, string T) {
        if(S.size() == 0) return "";
        if(T.size() > S.size()) return "";
        map<char, int>table1, table2;
        int cnt = T.size();
        int right = 0, left = 0;
        int faster = 0, slower = 0;
        for(int i = 0; i<T.size(); ++i) table1[T[i]]++;

        while(cnt>0&&faster<S.size())
        {
            if(table1.find(S[faster]) != table1.end())
            {
                table2[S[faster]]++;
                if(table2[S[faster]] <= table1[S[faster]])
                    cnt--;
            }
            faster++;
        }
        for(int i = 0; i<T.size(); ++i)
        {
            if(table1[T[i]] > table2[T[i]])
            return "";
        }

        for(int i = 0; i<S.size(); ++i)
        {
            if(table1.find(S[i]) != table1.end())
            {
                slower = i;
                break;
            }
        }

        left = slower;
        right = faster;

        while(slower < faster)
        {
            if(table2.find(S[slower]) != table2.end())
            {
                table2[S[slower]]--;
                if(table2[S[slower]] < table1[S[slower]])
                {
                    while(faster++ < S.size())
                    {
                        if(table2.find(S[faster-1]) != table2.end())
                        {
                            if(S[faster-1] != S[slower])
                            {
                                table2[S[faster-1]]++;
                            }
                            else
                            {
                                table2[S[faster-1]]++;
                                break;
                            }
                        }
                    }
                }
                if(table2[S[slower]] < table1[S[slower]])
                    break;
                else
                {
                    while(table1.find(S[++slower]) == table1.end());
                    if(faster - slower< right - left)
                    {
                        right = faster;
                        left = slower;
                    }
                    continue;
                }
            }
            slower++;
        }
        return S.substr(left, right-left);
    }
};
