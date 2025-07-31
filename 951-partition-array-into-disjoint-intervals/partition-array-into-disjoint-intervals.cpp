class Solution {
public:
    int partitionDisjoint(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> prefix(n);

        prefix[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
            prefix[i] = min( nums[i] , prefix[i+1] );

        int maxi = nums[0];
        for(int i=1;i<n;i++)
        {
            if(maxi <= prefix[i])
                return i;
            maxi = max(maxi, nums[i]);
        }
        return -1;
    }
};

