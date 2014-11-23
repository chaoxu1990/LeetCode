/*

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

class Solution {
public:
    bool isValid(const vector<string> &board, int row, int col, int n)
    {
        for(int i = 0; i<n; ++i)
        {
            if(( i != row && board[i][col] == 'Q')
             ||( i != col && board[row][i] == 'Q'))
              return false;
        }
        for(int j = 1; j<n; ++j)
        {
            if(row + j < n)
            {
                if(col + j < n)
                    if(board[row+j][col+j] == 'Q')
                        return false;
                if(col - j >= 0)
                    if(board[row+j][col-j] == 'Q')
                        return false;
            }
            if(row - j >= 0)
            {
                if(col + j < n)
                    if(board[row-j][col+j] == 'Q')
                        return false;
                if(col - j >= 0)
                    if(board[row-j][col-j] == 'Q')
                        return false;
            }
        }
        return true;
    }
    void helper(vector<vector<string> > &result, vector<string> &tmp, int row, int col, int cnt, int n)
    {
        if(row >= n)
        {
            if(cnt == n)
                result.push_back(tmp);
            return;
        }
            for(int j = 0; j<n; ++j)
            {
                if(tmp[row][j] == '.' && isValid(tmp, row, j, n) == true)
                {
                    tmp[row][j] = 'Q';
                    helper(result, tmp, row+1, j, cnt + 1, n);
                    tmp[row][j] = '.';
                }
            }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        vector<string> tmp(n, string(n,'.'));
        helper(result, tmp, 0,0, 0, n);

        return result;
    }
};
