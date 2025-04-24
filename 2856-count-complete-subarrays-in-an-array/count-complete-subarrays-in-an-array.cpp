class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        int k=s.size();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> mp;
            for(int j=i;j<n;j++)
            {
                mp[nums[j]]++;
                if(mp.size()==k)
                    count++;
            }
        }
        return count;
    }
};