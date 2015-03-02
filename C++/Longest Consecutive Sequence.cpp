/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int,bool> table;
        int cnt1 = 0, cnt2 = 0, result = 0, len = 0;
        for(int i: num)
            table[i] = true;

        for(int i: num)
        {
            if(table.find(i) != table.end())
            {
                cnt1 = 1, cnt2 = 1, len = 1;
                while(table.find(i-cnt1) != table.end() && table[i-cnt1] == true)
                {
                    table[i-cnt1] = false;
                    cnt1++;
                    len++;
                }

                while(table.find(i+cnt2) != table.end() && table[i+cnt2] == true)
                {
                    table[i+cnt2] = false;
                    cnt2++;
                    len++;
                }
                result = max(result, len);
            }
        }

        return result;
    }
};


//More concise solution with same logical above

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int,bool>table;
        int left = 0, right = 0, result = 0;
        for(int i:num)table[i] = true;
        for(int i:num)
        {
            left = right = 1;
            while(table.find(i-left) != table.end() && table[i-left] == true)table[i-left++]=false;
            while(table.find(i+right) != table.end() && table[i+right] == true)table[i+right++]=false;
            result = max(result,(right+left-1));
        }
        return result;
    }
};