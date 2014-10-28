/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/

//第一道自己做出来最优解的DP题，泪流满面。
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i<m; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                if(i==0&&j==0) continue;
                else if(i==0 && j!=0) grid[i][j] += grid[i][j-1];
                else if(i!=0 && j==0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
            }
        }

        return grid[m-1][n-1];
    }
};
