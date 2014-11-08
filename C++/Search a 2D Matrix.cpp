/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

*/

//My version:
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row_l = 0, row_r = matrix.size() - 1, row_mid = 0;
        int col_l = 0, col_r = matrix[0].size() - 1, col_mid = 0;

        while(row_l <= row_r)
        {
            row_mid = row_l + (row_r - row_l)/2;

            if(matrix[row_mid][0] < target) row_l = row_mid + 1;
            else if(matrix[row_mid][0] > target) row_r = row_mid - 1;
            else return true;
        }

        int row  = 0;

        if(matrix[row_mid][0] > target)
        {
            if(row_mid > 0)
                row = row_mid - 1;
            else
                row = 0;
        }
        else
            row = row_mid;

        while(col_l <= col_r)
        {
            col_mid = col_l + (col_r - col_l)/2;

            if(matrix[row][col_mid] < target) col_l = col_mid + 1;
            else if(matrix[row][col_mid] > target) col_r = col_mid - 1;
            else return true;
        }

        return false;
    }
};


//A better one:

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
       int row = matrix.size(), col = matrix[0].size();
       int l = 0, r = row * col;
       while(l<r)
       {
           int mid = l + (r-l)/2;
           int value = matrix[mid/col][mid%col];
           if(value < target) l = mid + 1;
           else if(value > target) r = mid;
           else return true;
       }

        return false;
    }
};
