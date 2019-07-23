/*
915. Partition Array into Disjoint Intervals

Given an array A, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

Example 1:

Input: [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]


Note:

2 <= A.length <= 30000
0 <= A[i] <= 10^6
It is guaranteed there is at least one way to partition A as described

*/


class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int sz= (int) A.size();
        int arrMax[1000005];
        int arrMin[1000005];

        memset(arrMax, 0, sz);
        memset(arrMin, 0, sz);

        int i, j, k, maxSo = 0 ;

        for(i=0; i<sz; i++)
        {
            maxSo= max(A[i], maxSo);
            arrMax[i] = maxSo;
        }
        int minSo = 10000000;
        for(i=sz-1; i>=0; i--)
        {
            minSo= min(A[i], minSo);
            arrMin[i] = minSo;
        }

        int res;
        for(i=0; i<sz-1; i++)
        {
            if(arrMax[i]<=arrMin[i+1]){
                res = i+1;
                break;
            }
        }

        return res;
    }
};
