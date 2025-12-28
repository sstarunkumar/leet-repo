class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int r = grid.size(), c = grid[0].size(), j = c - 1, ans = 0;
        for(int i=0;i<r;i++)
        {
            while( j >= 0 && grid[i][j] < 0 )
                j--;
            ans += c - j - 1;
        }
        return ans;
    }
};