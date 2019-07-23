#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>


using namespace std;
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
