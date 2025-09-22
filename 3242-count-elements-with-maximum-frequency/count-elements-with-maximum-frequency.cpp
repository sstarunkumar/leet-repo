class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        int maxi = 0;
        unordered_map<int,int> mp;
        for(int &i:nums)
        {
            mp[i]++;
            maxi = max(maxi, mp[i]);
        }
        int ans = 0;
        for(auto i = mp.begin();i!=mp.end();i++)
            if( i->second == maxi )
                ans += maxi;
        return ans;        
    }
};