class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int row = dungeon.size(), col = dungeon[0].size();
        vector<vector<int> > table(row, vector<int>(col, 0));
        table[row-1][col-1] = max(1, 1 - dungeon[row-1][col-1]);

        for(int i = row-2; i>=0; i--)
            table[i][col-1] = max(1, table[i+1][col-1] - dungeon[i][col-1]);

        for(int j = col-2; j>=0; j--)
            table[row-1][j] = max(1, table[row-1][j+1] - dungeon[row-1][j]);

        for(int i = row-2; i>=0; i--)
            for(int j = col-2; j>=0; j--)
                table[i][j] = max(1, min(table[i+1][j], table[i][j+1]) - dungeon[i][j]);

        return table[0][0];
    }
};
