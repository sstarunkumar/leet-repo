class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        int k = (unordered_set<int>(nums.begin(),nums.end())).size();
        int count = 0,left = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            while(mp.size() == k)
            {
                count += n-i;
                mp[nums[left]]--;
                if(mp[nums[left]]==0)
                    mp.erase(nums[left]);
                left++;
            }
        }
        return count;
    }
};