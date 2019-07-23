/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/

class Solution {
public:

    int bsearch_pivot(vector<int>& nums, int target, int low, int high)
    {
        cout<<"---- begin pivot"<<endl;

        while(low<high)
        {
            if(nums[low] == target)
                return low;

            int mid = (high+low)/2;
            cout<<low<<" "<<mid<<" "<<high<<endl;

            if(nums[mid] == target)
                return mid;

            else if(nums[low]<nums[mid]){
                low = mid;
            }
            else
                high = mid;
        }

        return -1;
    }

    int bsearch(vector<int>& nums, int target, int low, int high)
    {
        while(low<=high)
        {
            int mid = (high+low)/2;
            cout<<low<<" "<<mid<<" "<<high<<endl;
            if(nums[mid] == target)
                return mid;

            // First potion is sorted
            else if(nums[low] <= nums[mid])
            {
                if(target >= nums[low] && target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else{
                if( target >= nums[mid] && target <= nums[high])
                    low = mid + 1;
                 else
                     high = mid-1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;

        int res = 0;
        res= bsearch(nums, target, 0, nums.size()-1);
        return res;
    }
};
