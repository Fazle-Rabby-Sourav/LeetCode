/*

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int pos[256];
        int sz = s.size();

        memset(pos, -1, sizeof(pos));

        int ptr = 0, res=0;
        for(int i=0; i<sz; i++){
            if(pos[s[i]] >= 0)
            {
                ptr = max(ptr, pos[s[i]]+1) ;
            }
            res = max(res, (i-ptr)+1 );
            pos[s[i]] = i;
            cout<<s[i]<<" ptr: "<<ptr<<" res: "<<res<<endl;
        }
        return res;
    }
};
