class Solution {
public:
    int maxSum(vector<int>& nums) 
    {
        int ans = 0, min = INT_MIN;
        unordered_set<int> settu(nums.begin(),nums.end());
        for(auto i:settu)
        {
            if(i>0)
                ans += i;
            min = max(min,i);
        }    
        return min > 0 ? ans : min;
    }
};