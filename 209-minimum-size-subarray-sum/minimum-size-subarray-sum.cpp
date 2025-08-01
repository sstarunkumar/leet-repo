class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MAX;
        int left = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            while(sum >= target)
            {
                ans = min(ans,i-left+1);
                sum -= nums[left++];
            }
        }   
        return ans == INT_MAX ? 0 : ans;
    }
};