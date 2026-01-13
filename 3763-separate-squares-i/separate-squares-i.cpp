class Solution {
public:
    double uparea(vector< vector<int> > &squares, double k )
    {
        double area = 0;
        for(vector<int> & i : squares)
        {
            int x = i[0], y = i[1], s = i[2];
            if(y >= k)
                area += pow(s, 2);
            else if(y+s > k)
                area += (y + s - k) * s;
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) 
    {
        double area = 0;
        for(vector<int> & i : squares)
            area += pow(i[2], 2);
        area/=2;

        double lo = 0, hi = 1e9, ss = 0.00001;
        while(lo <= hi)
        {
            double mid = (lo+hi)/2;
            double up = uparea(squares, mid);
            if(up <= area)
                hi = mid - ss;
            else
                lo = mid + ss;
        }
        return hi;   
    }
};