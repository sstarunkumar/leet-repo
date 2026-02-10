class Solution {
public:
    int longestBalanced(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> odd, even;
        for(int i=0;i<n;i++)
        {
            odd.clear(), even.clear();
            for(int j=i;j<n;j++)
            {
                if(nums[j] & 1)
                    odd.insert(nums[j]);
                else
                    even.insert(nums[j]);
                ans = odd.size() == even.size() ? max(ans, j-i+1) : ans;
            }
        }
        return ans;
    }
};