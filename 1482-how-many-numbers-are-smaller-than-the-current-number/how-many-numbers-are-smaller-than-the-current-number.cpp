class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> fre(101,0);
        for(int i=0;i<n;i++)
            fre[nums[i]]++;
        for(int i=1;i<101;i++)
            fre[i]+=fre[i-1];
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                ans[i] = 0;
            else
                ans[i] = fre[nums[i]-1];
        }
        return ans;
    }
};