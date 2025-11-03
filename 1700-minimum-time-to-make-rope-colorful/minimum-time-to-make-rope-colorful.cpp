class Solution {
public:
    int minCost(string colors, vector<int>& need)
    {
        int n = colors.size();
        if(n == 1)
            return 0;
        int sum = 0;
        int maxi = need[0];
        for(int i=1;i<n;i++)
        {
            if(colors[i-1] == colors[i])
            {
                sum += min(maxi, need[i]);
                maxi = max(maxi, need[i]);
            }
            else
                maxi = need[i];
        }  
        return sum;
    }
};