class Solution {
public:
    bool check(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(),intervals.end());
        int sections = 0;
        int maxend = intervals[0][1];
        int x = intervals.size();
        for(int i=0;i<x;i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if( maxend <= start )
            {
                sections ++ ;
                if(sections > 1)
                    return true;
            }
            maxend = max(end , maxend);
        }
        return false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rect) 
    {
        vector<vector<int>> xtremes;
        vector<vector<int>> ytremes;
        for(auto i : rect) 
        {
            xtremes.push_back( { i[0],i[2] } );
            ytremes.push_back( { i[1],i[3] } );
        }   
        return check(xtremes) || check(ytremes);
    }
};