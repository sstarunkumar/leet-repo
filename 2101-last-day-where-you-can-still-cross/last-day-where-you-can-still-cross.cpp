class Solution 
{
public:
    vector< vector<bool> > vec;
    vector< vector<bool> > vis;
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
    bool pathfinder(int rows, int cols, int r, int c)
    {
        if(r == 0)
            return true;
        if(c <= 0 || c > cols || r > rows)
            return false;
        if( !vec[r][c] || vis[r][c] )
            return false;
        vis[r][c] = true;
        for(int i=0;i<4;i++)
            if( pathfinder(rows, cols, r+x[i], c+y[i]) )
                return true;
        return false;
    }
    bool haspath(int rows, int cols)
    {
        vis.assign(rows+1, vector<bool>(cols+1, false));
        for(int j=1; j<=cols; j++)
            if( vec[rows][j] && pathfinder(rows, cols, rows, j) )
                return true;
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        int n = cells.size();
        int lo = 0, hi = n-1, ans = -1;

        vec.assign(row+1, vector<bool>(col+1) );
        while( lo <= hi )
        {
            int mid = lo + (hi - lo)/2;
            for(int i=1;i<=row;i++)
                fill(vec[i].begin(), vec[i].end(), true);

            for(int i = 0; i <= mid; i++)
                vec[ cells[i][0] ][ cells[i][1] ] = false;
            
            if( haspath(row, col) )
            {
                ans = mid;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        return ans + 1;
    }
};