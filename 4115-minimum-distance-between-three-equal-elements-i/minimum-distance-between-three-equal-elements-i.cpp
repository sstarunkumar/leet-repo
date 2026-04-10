class Solution {
public:
    int minimumDistance(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, vector<int> > mp;
        for(int i=0;i<n;i++)
            mp[ nums[i] ].push_back(i);

        int ans = INT_MAX;
        for( auto p : mp )
        {
            vector<int> vec = p.second;
            int ss = vec.size();
            if( ss < 3 )
                continue;
            for(int i=2; i<ss ; i++)
            {
                int x = vec[i] - vec[i-1] +
                        vec[i] - vec[i-2] +
                        vec[i-1] - vec[i-2];
                ans = min(ans, x);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};