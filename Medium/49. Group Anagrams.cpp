/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> arr;
        arr.clear();

        for(int i=0; i<strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
         //   cout<<str<<endl;
            arr.push_back(make_pair(str, i));
        }
        sort(arr.begin(), arr.end());

        vector<vector<string>> res;
        res.clear();

        for(int i=0; i<arr.size(); i++)
        {
            cout<<arr[i].first<<endl;
        }



        vector<string> grp;
        grp.clear();

        string prev = "#";
        for(int i=0; i<arr.size(); i++)
        {
            if(prev!=arr[i].first)
            {
                if(i)
                    res.push_back(grp);

                grp.clear();
                grp.push_back(strs[ arr[i].second ]);
            }
            else
            {
                grp.push_back(strs[ arr[i].second ]);
            }

            prev = arr[i].first;
        }

        res.push_back(grp);

        return res;
    }
};
