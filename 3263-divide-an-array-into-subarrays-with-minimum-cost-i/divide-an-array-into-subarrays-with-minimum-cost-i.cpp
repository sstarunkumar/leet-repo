class Solution {
public:
    int minimumCost(vector<int>& nums) 
    {   
        // a 


        // b
        int ans = nums[0], n = nums.size();
        int a, b;
        a = b = INT_MAX;
        for(int i=1;i<n;i++)
        {
            if( nums[i] <= b )
            {
                a = b;
                b = nums[i];
            }
            else if(nums[i] < a)
                a = nums[i];
        }
        return ans + a + b;
    }
};