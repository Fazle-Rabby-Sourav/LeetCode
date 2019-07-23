/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/


class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindrome_recursive_way(s);
    }

    string findPalindrome(string s, int left, int right)
    {
        int n = s.size();
        int l = left;
        int r = right;
        while (left>=0 && right<=n-1 && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }


    // This is the common solution.
    // Actuatlly it's faster than DP solution under Leetcode's test
    // the below optimized DP solution need 700ms+, this needs around 250ms.
    string longestPalindrome_recursive_way(string s) {
        int n = s.size();
        if (n<=1) return s;

        string longest;

        string str;
        for (int i=0; i<n-1; i++) {
            str = findPalindrome(s, i, i);
            if (str.size() > longest.size()){
                longest = str;
            }
            str = findPalindrome(s, i, i+1);
            if (str.size() > longest.size()){
                longest = str;
            }
        }

        return longest;
    }
};
