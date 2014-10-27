/*

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

*/

//Solution No.1 using top-down logical.
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() == 1) return triangle[0][0];

        for(int i = 1; i<triangle.size(); ++i)
        {
            for(int j = 0; j<triangle[i].size(); ++j)
            {
                if(j==0) triangle[i][j] += triangle[i-1][0];
                else if(j==(triangle[i].size() - 1)) triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] = min(triangle[i][j] + triangle[i-1][j], triangle[i][j] + triangle[i-1][j-1]);
            }
        }
        int row = triangle.size()-1;
        int mini = triangle[row][0];

        for(int i = 1; i<triangle[row].size(); ++i)
        {
            if(mini > triangle[row][i])
                mini = triangle[row][i];
        }

        return mini;
    }
};

//Solution No.2 with bottom-up logical

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        for(int i = triangle.size()-2; i>=0; --i)
        {
            for(int j = 0; j<triangle[i].size(); ++j)
            {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }

        return triangle[0][0];
    }
};
