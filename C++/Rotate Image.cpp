/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/


class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if(matrix.size() == 0) return;
        int tmp = 0, row = matrix.size(), col = row;

        for(int i = 0; i<row; ++i)
        {
            for(int j = 0; j<col-i; ++j)
            {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[col - j - 1][row - i - 1];
                matrix[col - j - 1][row - i - 1] = tmp;
            }
        }

        for(int i = 0; i<row/2; ++i)
        {
            for(int j = 0; j<col; ++j)
            {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[row-i-1][j];
                matrix[row-i-1][j] = tmp;
            }
        }

        return;
    }
};
