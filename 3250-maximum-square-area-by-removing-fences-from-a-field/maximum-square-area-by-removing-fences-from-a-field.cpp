class Solution {
public:
    int mod = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) 
    {
        int r = hFences.size(), c = vFences.size();
        
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        vector<int> hdis(r+1);
        hdis[0] = hFences[0] - 1;
        hdis[r] = m - hFences[r-1];

        for(int i=1;i<r;i++)
            hdis[i] = hFences[i] - hFences[i-1];
        
        unordered_set<long long> hsums;
        long long sum;
        for(int i=0;i<=r;i++)
        {
            sum = 0;
            for(int j=i;j<=r;j++)
            {
                sum += hdis[j];
                hsums.insert(sum);
            }
        }

        vector<int> vdis(c+1);
        vdis[0] = vFences[0] - 1;
        vdis[c] = n - vFences[c-1];

        for(int i=1;i<c;i++)
            vdis[i] = vFences[i] - vFences[i-1];

        long long ans = -1;
        for(int i=0;i<=c;i++)
        {
            sum = 0;
            for(int j=i;j<=c;j++)
            {
                sum += vdis[j];
                if( hsums.count(sum) )
                    ans = max(ans, sum);
            }
        }
        if(ans == -1)
            return -1;
        ans = ans % mod;
        return (ans * ans) % mod;
    }
};