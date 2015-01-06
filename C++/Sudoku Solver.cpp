/*
Sudoku Solver
https://oj.leetcode.com/problems/sudoku-solver/
*/

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        helper(board,false);
    }
    
    bool helper(vector<vector<char> > &board, bool finished)
    {
        for(int i = 0; i<9; ++i)
            for(int j = 0; j<9; ++j)
                if(board[i][j] == '.')
                {   
                    for(int k = 1 + '0'; k<10 + '0'; ++k)
                        if(checkValid(i, j, board, 9, 9, k) == true)
                        {
                            board[i][j] = k;
                            if(helper(board, finished) == true)
                                return true;
                        }
                    board[i][j] = '.';
                    return false;
                }
       return true;
    }
    
    bool checkValid(int i, int j, vector<vector<char> > &board, int rowNum, int colNum, int num)
    {
        //check row
        for(int k = 0; k<colNum; ++k)
            if(num == board[i][k])
                return false;

        //check col
        for(int k = 0; k<rowNum; ++k)
            if(num == board[k][j])
                return false;
                
        //check 3x3 matrix
        int row = i/3, col = j/3;
        for(int r = 3*row; r<3*row+3; r++)
            for(int c = 3*col; c<3*col+3; c++)
                if(board[r][c] == num)
                    return false;
                    
        return true;
    }
};