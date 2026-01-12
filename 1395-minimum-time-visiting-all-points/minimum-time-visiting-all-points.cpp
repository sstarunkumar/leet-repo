class Solution 
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int n = points.size(), sum = 0;
        int a = points[0][0], b = points[0][1];
        int x, y;
        for(int i=1;i<n;i++)
        {
            x = points[i][0], y = points[i][1];
            sum += max( abs(x-a), abs(y-b) );
            a = x, b = y;
        }
        return sum;
    }
};