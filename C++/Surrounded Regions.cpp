/*

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

*/

class Solution {
public:
    queue<pair<int,int> > store;
    void solve(vector<vector<char>> &board) {
        if(board.size() < 2) return;
        if(board[0].size() < 2) return;

        int row = board.size();
        int col = board[0].size();

        for(int j = 0; j<col; ++j)
        {
            if(board[0][j] == 'O')
                bfs(board, 0, j);
        }

        for(int j = 0; j<col; ++j)
        {
            if(board[row-1][j] == 'O')
                bfs(board, row-1, j);
        }

        for(int i = 0; i<row; ++i)
        {
            if(board[i][0] == 'O')
                bfs(board, i, 0);
        }
        for(int i = 0; i<row; ++i)
        {
            if(board[i][col-1] == 'O')
                bfs(board, i, col-1);
        }

        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }

        return;
    }

    void bfs(vector<vector<char>> &board, int i, int j)
    {
        fill(board, i, j);

        while(store.empty() == false)
        {
            pair<int, int> tmp = store.front();
            store.pop();
            int row = tmp.first;
            int col = tmp.second;

            fill(board, row, col + 1);
            fill(board, row, col - 1);
            fill(board, row + 1, col);
            fill(board, row - 1, col);
        }

    }

    void fill(vector<vector<char>> &board, int i, int j)
    {
        int row = board.size();
        int col = board[0].size();

        if(i >= row || i < 0 || j >= col || j < 0) return;
        if(board[i][j] != 'O') return;
        store.push(pair<int,int>(i,j));

        board[i][j] = 'A';

    }
};

