/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/
//solution No.1: O(m*n) with one m*n array.
class Solution {
public:
    int uniquePaths(int m, int n) {
        int map[m][n];
        for(int i = 0; i<m; ++i)
            map[i][0] = 1;
        for(int j = 0; j<n; ++j)
            map[0][j] = 1;

        for(int i = 1; i<m; ++i)
        {
            for(int j = 1; j<n; ++j)
            {
                map[i][j] = map[i-1][j] + map[i][j-1];
            }
        }


    return map[m-1][n-1];
    }
};


//solution No.2 O(m*n) with one m array.
class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<int> map(n,0);

        map[0] = 1;


        for(int i = 0; i<m; ++i)
        {
            for(int j = 1; j<n; ++j)
                map[j] = map[j] + map[j-1];
        }

    return map[n-1];
    }
};
