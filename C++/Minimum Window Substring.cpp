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
        map<char, int>tableS, tableT;
        int cnt = 0, result_cnt = INT_MAX, result_start = 0;
        bool found = false;
        for(int i = 0; i<T.size(); ++i)
            tableT[T[i]]++;
        
        for(int fast = 0, slow = 0; fast<S.size();fast++)
        {
            if(tableT.find(S[fast]) != tableT.end())
            {
                if(tableS[S[fast]] < tableT[S[fast]])
                    cnt++;
                
                tableS[S[fast]]++;
                    
                if(cnt < T.size()){continue;}
               
                while(slow<=fast)
                {
                    if(tableT.find(S[slow]) != tableT.end())
                    {
                        if(cnt == T.size())
                        {
                            if(fast-slow+1 < result_cnt)
                            {
                                found = true;
                                result_cnt = fast-slow+1;
                                result_start = slow;
                            }
                        }
                    
                        tableS[S[slow]]--;
                        if(tableS[S[slow]] < tableT[S[slow]])
                            cnt--;
                            
                        if(cnt < T.size()){slow++; break;}
                    }
                    slow++;
                }
            }
        }
        
        if(found == true)
            return S.substr(result_start, result_cnt);
        else 
            return "";
    }
};