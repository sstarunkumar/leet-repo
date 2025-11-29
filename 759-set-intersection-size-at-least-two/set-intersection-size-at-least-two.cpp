class Solution 
{
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        sort( intervals.begin(), intervals.end(),
            [&](vector<int> a, vector<int> b)
            {
                return b[1] - a[1] > 0;
            }
        );
        
        int a = intervals[0][1] - 1;
        int b = intervals[0][1];
        int ans = 2;
        int x,y;
        for(int i=1;i<n;i++)
        {
            x = intervals[i][0];
            y = intervals[i][1];
            if(a >= x && a <= y)
            {}
            else if(b >= x && b <= y)
            {
                if(b == y)
                    a = y-1;
                else
                {
                    a = b;
                    b = y;
                }
                ans++;
            }
            else
            {
                a = y - 1;
                b = y;
                ans += 2;
            }
        }
        return ans;
    }
};