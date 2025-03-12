class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        int negative = -1;
        int positive = -1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i] < 0)
                negative = i;
            else if(nums[i] > 0 )
            {
                positive = i;
                break;
            }
        }
        if(positive != -1)
            positive = n - positive;
        negative ++;
        return max(positive,negative);
    }
};