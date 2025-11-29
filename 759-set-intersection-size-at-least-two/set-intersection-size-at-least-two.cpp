class Solution 
{
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        if(n == 1)
            return 2;
        sort( intervals.begin(), intervals.end(),
            [&](vector<int> a, vector<int> b)
            {
                return b[1] - a[1] > 0;
            }
        );
        
        int a,b;
        a = b = INT_MIN;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(a >= intervals[i][0] && a <= intervals[i][1])
            {}
            else if(b >= intervals[i][0] && b <= intervals[i][1])
            {
                if(b == intervals[i][1])
                {
                    a = intervals[i][1]-1;
                }
                else
                {
                    a = b;
                    b = intervals[i][1];
                }
                ans++;
            }
            else
            {
                a = intervals[i][1] - 1;
                b = intervals[i][1];
                ans += 2;
            }
        }
        return ans;
    }
};