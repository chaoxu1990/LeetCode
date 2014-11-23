/*

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

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

    void helper(vector<string> &tmp, int row, int col, int cnt, int n, int &count)
    {
        if(row >= n && cnt == n)
        {
            count++;
            return;
        }
            for(int j = 0; j<n; ++j)
            {
                if(tmp[row][j] == '.' && isValid(tmp, row, j, n) == true)
                {
                    tmp[row][j] = 'Q';
                    helper(tmp, row+1, j, cnt + 1, n, count);
                    tmp[row][j] = '.';
                }
            }
    }
    int totalNQueens(int n) {
        vector<string> tmp(n, string(n,'.'));
        int count = 0;
        helper(tmp, 0,0, 0, n, count);

        return count;
    }
};
