class Solution {
    public int[] productExceptSelf(int[] nums) 
    {
        int n = nums.length;
        int z = 0;
        int prod = 1;
        for(int i=0;i<n;i++)  
        {
            if(nums[i] == 0)
                z++;
            else
                prod = prod * nums[i];
        }
            
        if(z > 1)
            return new int[n];
        for(int i=0;i<n;i++)
        {
            if(z == 1)
            {
                if(nums[i] != 0)
                    nums[i] = 0;
                else
                    nums[i] = prod;
            }
            else
                nums[i] = prod/nums[i];
        }
        return nums;
    }
}