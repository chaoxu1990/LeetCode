/*

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if(numRows == 0) return result;

        for(int i = 0; i<numRows; ++i)
        {
            vector<int> tmp_result;
            for(int j = 0; j <= i; ++j)
            {
                if(j==0 || j==i)
                    tmp_result.push_back(1);
                else
                    tmp_result.push_back(result[i-1][j] + result[i-1][j-1]);
            }

            result.push_back(tmp_result);
        }

        return result;
    }
};
