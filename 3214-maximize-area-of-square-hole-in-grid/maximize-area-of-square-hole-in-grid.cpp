class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) 
    {
        int r = hBars.size(), c = vBars.size();

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int h = 1, v = 1, count = 1;
        for(int i=1;i<r;i++)
            if(hBars[i-1] + 1 == hBars[i])
            {
                count++;
                h = max(h, count);
            }
            else
                count = 1;

        count = 1;
        for(int i=1;i<c;i++)
            if(vBars[i-1] + 1 == vBars[i])
            {
                count++;
                v = max(v, count);
            }
            else
                count = 1;
                
        return pow( min(h, v) + 1, 2 );
    }
};