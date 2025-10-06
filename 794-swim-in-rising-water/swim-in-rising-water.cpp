class Solution 
{
public:
    vector<int> x = {1,-1,0,0};
    vector<int> y = {0,0,1,-1};
    vector< vector<bool> > vis;
    void reachable(vector<vector<int>> &grid,int n,int k,int i,int j)
    {
        if( i<0 || j<0 || i>=n || j>=n || grid[i][j] > k )
            return ;
        if( vis[i][j] )
            return ;

        vis[i][j] = true;
        for(int bot=0;bot<4;bot++)
            reachable(grid,n,k,i+x[bot],j+y[bot]);

    }
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int lo = grid[n-1][n-1],hi = n*n;
        int ans = n*n;

        while( lo <= hi )
        {
            vis.assign(n,vector<bool>(n,false));
            int mid = lo + (hi-lo)/2;
            reachable(grid,n,mid,0,0);
            if( vis[n-1][n-1] )
            {
                ans = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }    
        return ans;
    }
};