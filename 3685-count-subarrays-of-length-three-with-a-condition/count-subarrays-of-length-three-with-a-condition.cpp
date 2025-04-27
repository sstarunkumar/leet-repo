class Solution {
public:
    int countSubarrays(vector<int>& nums) 
    {
        int ans = 0;
        int n= nums.size();
        for(int i=1;i<n-1;i++)
            if( nums[i-1] + nums[i+1] == floor(nums[i])/2)
                ans++;
        return ans;   
    }
};