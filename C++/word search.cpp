class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<bool>> visited (m, vector<bool>(n,false));

        for(int i = 0; i<m; ++i)
            for(int j = 0; j<n; ++j)
                if(dfs(board, word, i, j, 0, visited))
                    return true;

        return false;
    }
private:
    static bool dfs(vector<vector<char> > &board, const string &word, int m, int n, int cnt, vector<vector<bool>> &visited)
    {
        if(cnt == word.size()) return true;

        if(m<0||m>=board.size()||n<0||n>=board[0].size()) return false;
        if(visited[m][n]) return false;
        if(word[cnt] != board[m][n]) return false;

        visited[m][n] = true;
        bool ret =
                dfs(board, word, m+1, n, cnt+1, visited)||
                dfs(board, word, m-1, n, cnt+1, visited)||
                dfs(board, word, m, n+1, cnt+1, visited)||
                dfs(board, word, m, n-1, cnt+1, visited);
        visited[m][n] = false;

        return ret;

    }
};
