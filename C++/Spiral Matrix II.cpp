/*

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int begin = 0, end = n - 1, num = 1;
        vector<vector<int> > result(n,vector<int>(n,0));
        while(begin<end)
        {
            for(int i = begin; i<end; ++i) result[begin][i] = num++;
            for(int j = begin; j<end; ++j) result[j][end] = num++;
            for(int i = end; i>begin; --i) result[end][i] = num++;
            for(int j = end; j>begin; --j) result[j][begin] = num++;
            begin++;
            end--;
        }

        if(begin == end) result[begin][end] = num;

        return result;
    }
};
