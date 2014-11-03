/*

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

*/


class Solution {
public:
    bool check(char ch, bool used[9])
    {
        if(ch == '.') return true;
        if(used[ch - '1']) return false;
        used[ch - '1'] = true;

        return true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        bool used[9];

        for(int i = 0; i<9; ++i)
        {
            fill(used, used+9, false);
            for(int j = 0; j<9; ++j)
                if(!check(board[i][j], used))
                    return false;

            fill(used, used+9, false);
            for(int j = 0; j<9; ++j)
                if(!check(board[j][i], used))
                    return false;

            for(int r = 0; r<3; ++r)
                for(int c = 0; c<3; ++c)
                {
                    fill(used, used+9, false);
                    for(int i = 3*r; i<r*3 + 3; ++i)
                        for(int j = 3*c; j<3*c + 3; ++j)
                            if(!check(board[i][j], used))
                                return false;
                }


        }
        return true;
    }
};
