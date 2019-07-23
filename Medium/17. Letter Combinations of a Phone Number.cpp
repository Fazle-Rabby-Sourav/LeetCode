/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/


class Solution {
public:
    vector <string> res;
    map <char, string> buttonMap;

    void rec(int now, string res_str, string digits){

        if(now==digits.size())
        {
            res.push_back(res_str);
            return;
        }

        string candidate = buttonMap[digits[now]];
        for(int i=0; i<candidate.size(); i++)
        {
            rec(now+1, res_str+candidate[i], digits);
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        buttonMap['2'] = "abc";
        buttonMap['3'] = "def";
        buttonMap['4'] = "ghi";
        buttonMap['5'] = "jkl";
        buttonMap['6'] = "mno";
        buttonMap['7'] = "pqrs";
        buttonMap['8'] = "tuv";
        buttonMap['9'] = "wxyz";

        res.clear();

        if(digits.size()==0)
            return res;

        rec(0, "", digits);

        return res;

    }
};
