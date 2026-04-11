class Solution {
public:
    int minimumDistance(vector<int>& nums) 
    {
        int n = nums.size();
        vector< pair<int, int> > vec(n);
        for(int i=0;i<n;i++)
            vec[i] = { nums[i], i } ;

        sort( vec.begin(), vec.end() );

        int ans = INT_MAX;
        for(int i=2;i<n;i++)
        {
            if( vec[i].first == vec[i-1].first && vec[i-1].first == vec[i-2].first )
            {
                int x = vec[i].second - vec[i-1].second +
                        vec[i].second - vec[i-2].second +
                        vec[i-1].second - vec[i-2].second ;
                ans = min(ans, x);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};