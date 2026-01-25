class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) 
    {
        if(k == 1)
            return 0;
        
        int n = nums.size() ;
        sort(begin(nums), end(nums));
        
        int ans = nums[k-1] - nums[0];
        for(int i=k;i<n;i++)
            ans = min(ans, nums[i] - nums[i-k+1]);

        return ans;
    }
    //1 4 7 9
};