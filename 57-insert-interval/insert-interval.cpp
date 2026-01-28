class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int a = newInterval[0], b = newInterval[1];
        int n = intervals.size();
        int mini = a, maxi = b;
        vector<int> indices;
        for(int i=n-1;i>=0;i--)
        {
            int x = intervals[i][0], y = intervals[i][1];
            if( y < a )
                continue;
            else if(x > b)
                continue;
            else
            {
                mini = min(mini, x);
                maxi = max(maxi, y);
                indices.push_back(i);
            }

        }    
        for(int i: indices)
            intervals.erase(intervals.begin() + i);
        intervals.push_back( {mini, maxi} );
        sort( begin(intervals), end(intervals) );
        return intervals;
    }
};