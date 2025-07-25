class Solution {
public:
    int maxSum(vector<int>& nums) 
    {
        int sum = 0,ans = INT_MIN;
        set<int> settu(nums.begin(),nums.end());
        for(auto i:settu)
        {
            sum += i;
            ans = max(ans,sum);
            if(sum < 0)
                sum = 0;
        } 
        return ans;
    }
};