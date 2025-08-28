class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        for(int i=n-1;i>0;i--)
        {
            int a = 0,b = i;
            priority_queue<int,vector<int>,greater<>> pq;
            while(a<n && b<n)
            {
                pq.push(grid[a++][b++]);
            }
            a = 0,b = i;
            while(a<n && b<n)
            {
                grid[a++][b++] = pq.top();
                pq.pop();
            }
        }
        for(int i=0;i<n;i++)
        {
            int a = i, b = 0;
            priority_queue<int> pq;
            while(a<n && b<n)
            {
                pq.push(grid[a++][b++]);
            }
            a = i, b = 0;
            while(a<n && b<n)
            {
                grid[a++][b++] = pq.top();
                pq.pop();
            }
        }
        return grid;

    }
};