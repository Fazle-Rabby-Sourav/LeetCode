#include <string>

class Solution {
public:
    vector <string> res;

    void rec(int L, int R, string str)
    {
        if(R==0 && L==R){
            res.push_back(str);
            return;
        }

        if(L>0)
            rec(L-1, R, str+"(");
        if(L<R)
            rec(L, R-1, str+")");

        return;
    }

    vector<string> generateParenthesis(int n) {
        res.clear();
        int L, R;
        L=n ;
        R=n;
        string str="(";
        if(n>0)
            rec(L-1, R, str);

        return res;
    }



};
