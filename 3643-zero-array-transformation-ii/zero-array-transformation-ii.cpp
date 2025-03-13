class Solution {
public:
    bool iszero(vector<int> &vec,vector<int> &rods)
    {
        int value=0;
        int n=vec.size();
        for(int i=0;i<n;i++)
        {
            value+=rods[i];
            if(vec[i] - value > 0)
                return false;
        }
        return true;
    }
    int minZeroArray(vector<int> &vec, vector<vector<int>> &index) 
    {
        int n = vec.size();
        int rows = index.size();
        int lo = 0;
        int hi = rows-1;
        int ans=-1;
        vector<int> rods(n+1,0);
        if( iszero(vec,rods) )
            return 0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            fill(rods.begin(),rods.end(),0);
            for(int i=0;i<=mid;i++)
            {
                rods[ index[i][0] ] += index[i][2];
                rods[ index[i][1]+1 ] -= index[i][2];
            }
            if( iszero(vec,rods) )
            {
                ans=mid+1;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        return ans;
    }
};