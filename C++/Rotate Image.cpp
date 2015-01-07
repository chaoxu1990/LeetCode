/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/


class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int rowNum = matrix.size(), colNum = matrix[0].size();
        
        for(int i = 0; i<rowNum; i++)
            for(int j = 0; j<colNum/2; j++)
                swap(matrix[i][j], matrix[i][colNum-j-1]);
                
        for(int i = 0; i<rowNum; i++)
            for(int j = 0; j<rowNum-i-1; j++)
                swap(matrix[i][j], matrix[colNum-j-1][rowNum-i-1]);        
    }
};