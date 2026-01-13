class Solution {
public:
    double uparea(vector< vector<int> > &squares, double k )
    {
        double area = 0;
        for(vector<int> & i : squares)
        {
            if(i[1] >= k)
                area += pow(i[2], 2);
            else if(i[1]+i[2] > k)
                area += (i[1] + i[2] - k) * i[2];
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) 
    {
        double area = 0, lo = 0, hi = 1e9, ss = 0.00001, mid, up;
        for(vector<int> & i : squares)
            area += pow(i[2], 2);
        area/=2;

        while(lo <= hi)
        {
            mid = (lo+hi)/2;
            up = uparea(squares, mid);
            if(up <= area)   hi = mid - ss;
            else             lo = mid + ss;
        }
        return lo;   
    }
};