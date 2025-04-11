class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=0;i<=n;i++)
        {
            bool flag = true;
            for(int j=0;j<n;j++)
            {
                if(nums[j] == i)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                return i;
        }
        return -1;
    }
};