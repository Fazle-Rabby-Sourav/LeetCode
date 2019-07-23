/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,
  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {

        int level = 1;
        long long int d = abs((long long)divisor);
        long long int rest = abs((long long)dividend);
        int cnt = 0;


       if(dividend == INT_MIN && divisor==-1){
                return INT_MAX;
        }

        if(divisor == 1 )
            return dividend;

        while(level>0){

            if(rest>=d){

                rest = rest-d;
                cnt+= level;

                d = (d<<1);
                level = (level<<1);
            }
            else{
                d = (d>>1);
                level = (level>>1);

                if(rest >= d){
                     rest -= d;
                     cnt += level;
                }
            }
        }


            if(dividend <0 && divisor<0)
                return cnt;

            if(dividend <0 && divisor>0)
                return -cnt;

            if(dividend >0 && divisor<0)
                return cnt = -cnt;

        return cnt;
    }
};
