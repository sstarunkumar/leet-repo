class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) 
    {
        int h = 1;
        unordered_set<int> settu(hBars.begin(), hBars.end());
        for(int & i : hBars)
        {   
            int t = i-1, c = 1;
            while( settu.count(t) )
            {
                c++;
                t--;
            }
            settu.insert(i);
            h = max(h, c);
        }
        settu = unordered_set<int>(vBars.begin(), vBars.end());
        int v = 1;
        for(int & i : vBars)
        {
            int t = i-1, c = 1;
            while( settu.count(t) )
            {
                t--;
                c++;
            }
            settu.insert(i);
            v = max(v, c);
        }
        return pow( min(h, v) + 1, 2 );
    }
};