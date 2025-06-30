class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        map<int,int> mp;
        for(int &i:nums)
            mp[i]++;
        if(mp.size() == 1)
            return 0;
        auto p = mp.begin(),i = mp.begin();
        i++;
        int ans = 0;
        while(i!=mp.end())
        {
            if(i->first - p->first == 1)
                ans = max(ans, i->second + p->second);
            p = i;
            i++;
        }
        return ans;
    }
};