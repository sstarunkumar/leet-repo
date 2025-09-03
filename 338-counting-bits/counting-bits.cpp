class Solution {
public:
    vector<int> countBits(int n) 
    {
        if( n == 0 )
            return {0};
        vector<int> ans(n+1);
        ans[0] = 0;
        ans[1] = 1;
        for(int i=2;i<=n;i++)
            ans[i] = ans[i/2] + (i&1) ;
        return ans;
    }
};