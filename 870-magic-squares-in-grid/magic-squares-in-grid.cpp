class Solution {
public:
    bool valid(vector< vector<int> > &grid, int a, int b)
    {
        for(int i=0;i<3;i++)
        {
            int sum = 0;
            for(int j=0;j<3;j++)
            {
                if(grid[a+i][b+j] == 0 || grid[a+i][b+j] > 9)
                    return false;
                sum += grid[a+i][b+j];
            }
            if(sum != 15)
                return false;
        }
        if(grid[a+0][b+0] + grid[a+1][b+1] + grid[a+2][b+2] != 15)
            return false;
        if(grid[a+0][b+2] + grid[a+1][b+1] + grid[a+2][b+0] != 15)
            return false;
        
        unordered_set<int> settu;
        for(int j=0;j<3;j++)
        {
            int sum = 0;
            for(int i=0;i<3;i++)
            {
                if(settu.count( grid[a+i][b+j] ))
                    return false;
                settu.insert( grid[a+i][b+j] );
                sum += grid[a+i][b+j];
            }
            if(sum != 15)
                return false;
        }
        return true;          
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        int r = grid.size(), c = grid[0].size();
        if(r < 3 || c < 3)
            return 0;
        int ans = 0;
        for(int i = 0 ; i < r-2 ; i++ )
        {
            for(int j=0; j < c-2 ; j++)
                if( valid(grid, i, j) )
                    ans++;
        }    
        return ans;
    }
};