class Solution {
public:
    int minimumDistance(vector<int>& nums) 
    {
        int n = nums.size();
        vector< vector<int> > vec(n, vector<int>(2));
        for(int i=0;i<n;i++)
        {
            vec[i][0] = nums[i];
            vec[i][1] = i;
        }    
        sort( vec.begin(), vec.end() );

        int ans = INT_MAX;
        for(int i=2;i<n;i++)
        {
            if(vec[i-2][0] == vec[i-1][0] && vec[i-1][0] == vec[i][0])
            {
                int x = vec[i][1] - vec[i-1][1] +
                        vec[i][1] - vec[i-2][1] +
                        vec[i-1][1] - vec[i-2][1] ;
                ans = min(ans, x);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};