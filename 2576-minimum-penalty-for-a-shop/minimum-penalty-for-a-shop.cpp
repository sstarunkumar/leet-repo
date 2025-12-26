class Solution {
public:
    int bestClosingTime(string customers) 
    {
        int n = customers.size();
        vector<int> ones(n+1, 0);
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(customers[i] == 'N')
                c++;
            ones[i+1] = c;
        }
        c = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(customers[i] == 'Y')
                c++;
            ones[i] += c;
        }
        int ans = 0, val = INT_MAX;
        for(int i=0;i<=n;i++)
            if(ones[i] < val)
            {
                val = ones[i];
                ans = i;
            }
        return ans;
    }
};