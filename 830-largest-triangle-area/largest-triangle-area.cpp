class Solution {
public:
    double area(vector<int> &i,vector<int> &j,vector<int> &k)
    {
        return 0.5 * abs( i[0]*j[1] + j[0]*k[1] + k[0]*i[1]
                            - i[1]*j[0] - j[1]*k[0] - k[1]*i[0] );
    }
    double largestTriangleArea(vector<vector<int>>& points) 
    {
        int n = points.size();
        double ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++)
                    ans = max(ans, area(points[i], points[j], points[k]));
        }    
        return ans;
    }
};