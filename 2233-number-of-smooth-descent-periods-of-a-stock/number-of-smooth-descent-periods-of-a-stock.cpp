class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) 
    {
        int n = prices.size();
        long long ans = n;
        int c = 0;
        for(int i=1;i<n;i++)
        {
            if( prices[i-1] == prices[i]+1 )
            {
                c++;
                ans += c;
            }
            else
                c = 0;
        }
        return ans;
    }
};