/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() == 0) return 0;
        const int row = matrix.size();
        const int col = matrix[0].size();
        vector<int> l(col, 0), r(col, col), h(col, 0);
        int result = 0;
        for(int i = 0; i<row; ++i)
        {
            int left = 0, right = col;
            for(int j = 0; j<col; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    l[j] = max(left, l[j]);
                    ++h[j];
                }
                else
                {
                    l[j] = 0;
                    h[j] = 0;
                    r[j] = col;
                    left = j + 1;
                }
            }

            for(int j = col-1; j>=0; --j)
            {
                if(matrix[i][j] == '1')
                {
                    r[j] = min(r[j], right);
                    result = max(result, h[j]*(r[j]-l[j]));
                }
                else
                {
                    right = j;
                }
            }
        }
        return result;
    }
};
