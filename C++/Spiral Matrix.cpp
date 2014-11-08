/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if(matrix.size() == 0) return vector<int>();

        int beginx = 0, beginy = 0, endx = matrix[0].size(), endy = matrix.size();
        vector<int> result;
        //bool left = false, right = false, up = false, down = false;
        while(true)
        {
            //from left to right
            for(int i = beginx; i<endx; ++i) result.push_back(matrix[beginy][i]);
            if(++beginy >= endy) break;
            //from up to down
            for(int i = beginy; i<endy && endx>0; ++i) result.push_back(matrix[i][endx-1]);
            if(--endx <= beginx) break;
            //from right to left
            for(int i = endx-1; i>=beginx && endy>0; --i) result.push_back(matrix[endy-1][i]);
            if(--endy <= beginy) break;
            //from down to up
            for(int i = endy-1; i>=beginy; --i) result.push_back(matrix[i][beginx]);
            if(++beginx>=endx) break;
        }

        return result;
    }
};
