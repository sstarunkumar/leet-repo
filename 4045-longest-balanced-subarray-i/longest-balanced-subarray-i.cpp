class Solution {
public:
    bool valid(vector<int> &nums, int start, int k)
    {
        unordered_set<int> even, odd;
        for(int i=start; i < start + k; i++)
            if( nums[i] & 1 )
                odd.insert(nums[i]);
            else
                even.insert(nums[i]);
        return odd.size() == even.size();
    }
    int longestBalanced(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            unordered_set<int> odd, even;
            for(int j=i;j<n;j++)
            {
                if(nums[j] & 1)
                    odd.insert(nums[j]);
                else
                    even.insert(nums[j]);
                ans = odd.size() == even.size() ? max(ans, j-i+1) : ans;
            }
        }
        return ans;
    }
};