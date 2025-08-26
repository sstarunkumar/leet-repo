class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) 
    {
        int n = dimensions.size();
        double sq = 0;
        double m = 0;
        int ans = 0;
        for(int i=0;i<n;i++)    
        {
            int l = dimensions[i][0], r = dimensions[i][1];
            sq = sqrt(l*l + r*r);
            if(sq > m)
            {
                m = sq;
                ans = l*r;
                cout<<i<<" ";
            }
            else if(sq == m)
                ans = max(ans,l*r);
        }
        return ans;
    }
};