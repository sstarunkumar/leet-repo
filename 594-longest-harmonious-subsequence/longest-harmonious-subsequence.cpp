class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int curr = nums[0], prev = nums[0];
        int n = nums.size();
        int ans = 0,count = 1,prevcount = 0;
        for(int i=1;i<n;i++)
            if(nums[i]!=curr)
            {
                if(curr - prev == 1)
                    ans = max(ans , count + prevcount);
                prev = curr;
                curr = nums[i];
                prevcount = count;
                count = 1;
            }
            else
                count ++;
            if(curr - prev == 1)
                ans = max(ans , count + prevcount);
        return ans;
    }
};