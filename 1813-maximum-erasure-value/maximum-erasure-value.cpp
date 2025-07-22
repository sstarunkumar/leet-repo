class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0,ans = 0;
        unordered_set<int> se;
        int l = 0;
        for(int i=0;i<n;i++)
        {
            if(se.find(nums[i]) != se.end())
            {
                while(nums[l] != nums[i])
                {
                    sum -= nums[l];
                    se.erase(nums[l]);
                    l++;
                }
                l++;
            }
            else
            {
                se.insert(nums[i]);
                sum += nums[i];
                ans = max( ans,sum );
            }
        } 
        return ans;   
    }
};