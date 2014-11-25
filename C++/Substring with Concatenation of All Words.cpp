/*

You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        map<string, int> table;
        int word_size = L[0].size();
        int word_nums = L.size();
        vector<int> result;
        for(int i = 0; i<L.size(); ++i)
            table[L[i]]++;

        for(int i = 0; i + word_size * word_nums < S.size() + 1; ++i)
        {
            int j = 0;
            map<string, int> table2;
            while(j < word_nums)
            {
                string tmp_word = S.substr(i + j*word_size, word_size);
                table2[tmp_word]++;
                if(table.find(tmp_word) == table.end() || table2[tmp_word] > table[tmp_word])
                    break;
                else
                    j++;
            }
            if(j==word_nums)
                result.push_back(i);
        }

        return result;
    }
};
