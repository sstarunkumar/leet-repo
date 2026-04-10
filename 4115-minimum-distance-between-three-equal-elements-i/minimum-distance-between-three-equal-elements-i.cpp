class Solution {
public:
    int minimumDistance(vector<int>& nums) 
    {
        int n = nums.size();
        vector< vector<int> > vec(101);
        for(int i=0;i<n;i++)
            vec[ nums[i] ].push_back(i);
        
        int ans = INT_MAX;
        for(int i=0; i<=100 ; i++ )
        {
            int ss = vec[i].size();
            if(ss < 3)
                continue;
            for(int j=2; j < ss ; j++ )
            {
                int x = vec[i][j] - vec[i][j-1] + 
                        vec[i][j] - vec[i][j-2] + 
                        vec[i][j-1] - vec[i][j-2] ;
                ans = min(ans, x);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};