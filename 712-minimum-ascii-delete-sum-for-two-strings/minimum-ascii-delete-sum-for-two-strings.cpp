class Solution {
public:
    vector< vector<int> > dp;
    int mds(string &s1, string &s2, int a, int b)
    {
        if(a < 0)
        {
            int sum = 0;
            for(int i=0;i<=b;i++)
                sum += s2[i];
            return sum;
        }
        if(b < 0)
        {
            int sum = 0;
            for(int i=0;i<=a;i++)
                sum += s1[i];
            return sum;
        }
        if(dp[a][b] != -1)
            return dp[a][b];
        if(s1[a] == s2[b])
            return dp[a][b] = mds(s1, s2, a-1, b-1);
        return dp[a][b] = min( mds(s1, s2, a-1, b) + s1[a] , mds(s1, s2, a, b-1) + s2[b] );
    }
    int minimumDeleteSum(string s1, string s2) 
    {
        int a = s1.size(), b = s2.size();
        dp.assign( a, vector<int> (b, -1) );
        return mds(s1, s2, a-1, b-1);
    }
};