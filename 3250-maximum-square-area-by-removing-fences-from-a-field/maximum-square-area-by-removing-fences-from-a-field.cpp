class Solution {
public:
    int mod = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) 
    {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        int r = hFences.size();
        int c = vFences.size();

        vector<int> hdis(r-1);
        for(int i=1;i<r;i++)
            hdis[i-1] = hFences[i] - hFences[i-1];
        
        unordered_set<long long> hsums;
        for(int i=0;i<r-1;i++)
        {
            long long sum = 0;
            for(int j=i;j<r-1;j++)
            {
                sum += hdis[j];
                hsums.insert(sum);
            }
        }

        vector<int> vdis(c-1);
        for(int i=1;i<c;i++)
            vdis[i-1] = vFences[i] - vFences[i-1];

        long long ans = -1;
        for(int i=0;i<c-1;i++)
        {
            long long sum = 0;
            for(int j=i;j<c-1;j++)
            {
                sum += vdis[j];
                if( hsums.count(sum) )
                    ans = max(ans, sum);
            }
        }
        ans = ans % mod;
        return ans == -1 ? -1 : (ans * ans) % mod;
    }
};