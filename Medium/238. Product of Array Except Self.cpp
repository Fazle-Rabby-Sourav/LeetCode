class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int prod=1;
        int cnt =0;
        for(int i=0; i<(int)nums.size(); i++){

            if(nums[i]==0){
                cnt++;
                continue;
            }
            prod *= nums[i];
        }

        vector <int> res;
        res.clear();
        for(int i=0; i<(int)nums.size(); i++)
        {
            if(cnt>1)
                res.push_back(0);
            else if(cnt==1)
            {
                if(nums[i]==0)
                    res.push_back(prod);
                else
                    res.push_back(0);
            }
            else
                res.push_back(prod/nums[i]);
        }

        return res;

    }
};
