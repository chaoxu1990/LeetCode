/*

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        vector<int> tmp_result;

        for(int i = 0; i<=rowIndex; ++i)
        {
            for(int j = 0; j<=i; ++j)
            {
                if(j==i)
                    tmp_result.push_back(1);
                else if(j==0)
                    tmp_result[j] = 1;
                else
                    tmp_result[j] = (result[j] + result[j-1]);
            }
            result = tmp_result;
        }

        return result;
    }
};
