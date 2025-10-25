class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        int x = 1e6;
        for(int i=0;i<n;i++)
            if( nums[i] <= 0 || nums[i] > n)
                nums[i] = x ;
        for(int i=0;i<n;i++)
        {
            int k = abs( nums[i] );
            if(k != x)
                nums[k-1] = - abs( nums[k-1] ) ; 
        }
        for(int i=0;i<n;i++)
            if(nums[i] > 0)
                return i+1;
        return n+1;
    }
};