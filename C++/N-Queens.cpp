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
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> tmp_result(n, string(n, '.'));
        helper(result, tmp_result, n, 0);
        return result;
    }
    
    void helper(vector<vector<string> > &result, vector<string> tmp_result, int n, int row)
    {
        if(row == n){result.push_back(tmp_result);return;}
        
        for(int i = 0; i<n; i++)
            if(isValid(row, i, tmp_result, n))
            {
                tmp_result[row][i] = 'Q';
                helper(result, tmp_result, n, row+1);
                tmp_result[row][i] = '.';
            }
    }
    
    bool isValid(int row, int col, vector<string> tmp_result, int n)
    {
        //check col
        for(int i = 0; i<n; i++)
            if(tmp_result[i][col] == 'Q')
                return false;
        //check diagonal
        
        for(int i = 0; i<n; i++)
        {
            if(row - i >= 0 && col - i >= 0)
                if(tmp_result[row-i][col-i] == 'Q')
                    return false;

            if(row - i >= 0 && col + i < n)
                if(tmp_result[row-i][col+i] == 'Q')
                    return false;

            if(row + i < n && col - i >= 0)
                if(tmp_result[row+i][col-i] == 'Q')
                    return false;
                    
            if(row + i < n && col + i < n)
                if(tmp_result[row+i][col+i] == 'Q')
                    return false;
        }
        
        return true;
    }
};