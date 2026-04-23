class Solution {
public:
    vector<long long> distance(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map< int, vector<int> > mp;
        for(int i = 0; i < n; i++ )
            mp[ nums[i] ].push_back(i);
        
        vector<long long> ans(n,0), ans2(n, 0);
        for(auto mpi : mp)
        {
            vector<int> vec = mpi.second;
            int s = vec.size();
            if(s == 1)
                continue;

            for(int i=1; i<s; i++)
            {
                int d = vec[i] - vec[i-1];
                ans[ vec[i] ] = ans[ vec[i-1] ] + i * d;
            }
            for(int i = s-2, j = 1; i >= 0; i--, j++)
            {
                int d = vec[i+1] - vec[i];
                ans2[ vec[i] ] = ans2[ vec[i+1] ] + j * d;
            }
        }
        for(int i=0;i<n;i++)
            ans2[i] += ans[i];
        return ans2;
    }
};