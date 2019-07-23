/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> res;
        res.clear();
        int m, n, i, j;
        int round=0;

        m = matrix.size();
        if(!m)
            return res;

        n = matrix[0].size();
        if(!n)
            return res;



        i = j = 0;
        int flag = 1;
        while(flag)
        {
            flag = 0;
            while(j< (n-round)){
                res.push_back(matrix[i][j++]);
                flag = 1;
            }
            if(!flag) return res;
            --j;             i++;


            flag = 0;
            while(i< (m-round)){
                res.push_back(matrix[i++][j]);
                flag = 1;
            }
            if(!flag) return res;
            --i;            --j;


            flag = 0;
            while(j >= round){
                res.push_back(matrix[i][j--]);
                flag = 1;
            }
            if(!flag) return res;
            ++j;            --i;


            flag = 0;
            while(i > round){
                res.push_back(matrix[i--][j]);
                flag = 1;
            }
            if(!flag) return res;
            ++i;            ++j;

            round++;
        }

        return res;
    }
};
