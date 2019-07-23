/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        res.clear();

        for (int i = 0; i<nums.size(); i++)
        {
            // To eliminate Duplicate items
            if(i-1>= 0 && nums[i] == nums[i-1])
                continue;

            // Two pointer Implementation
            int left = i+1;
            int right = nums.size()-1;
            while(left<right)
            {
                // To eliminate Duplicate items
                if(left>i+1 && nums[left] == nums[left-1])
                    left++;

                else if(nums[i] + nums[left] + nums[right] == 0 )
                {
                    vector<int> temp;
                    temp.clear();
                    temp.push_back(nums[i]); temp.push_back(nums[left]); temp.push_back(nums[right]);

                    res.push_back(temp);
                    left++;
                    right--;
                }
                else if(nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else
                    right--;
            }

        }

        return res;
    }
};
