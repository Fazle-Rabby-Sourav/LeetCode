/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/


class Solution {
public:


    double bigPow(double x, long long n)
    {
        if(n == 0)
            return 1.0;


        double res;
        if(n%2 == 0)
        {
            res = bigPow(x, n/2);
            res = res*res;
             // cout<<x<<" "<<n<<" "<<res<<endl;
        }
        else
            res = x*bigPow(x, n-1);

        return res;

    }


    double myPow(double x, int n) {

        double res;
        long long int ln = n;
        if(ln<0)
        {
            ln = -ln;
            // cout<<" n : "<<ln<<endl;
            res = bigPow(x, ln);
            res = 1.0/res;
        }
        else
            res = bigPow(x, ln);

        // cout<<"Final Res : "<<res;
        return res;
    }
};
