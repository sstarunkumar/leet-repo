class Solution {
public:
    double max(double a, double b)
    {
        return a > b ? a : b;
    }
    double champagneTower(int poured, int row, int col) 
    {   
        if(row == 0)
            return min(1, poured);
        
        vector< vector<double> > vec(row + 1);
        for(int i=0;i<=row;i++)
            vec[i] = vector<double> (i+1);
        
        vec[0][0] = poured;
        for(int i=1;i<=row;i++)
        {
            vec[i][0] = max(0, (vec[i-1][0] - 1)/2 );

            for(int j=1;j<i;j++)
                vec[i][j] = max(0, (vec[i-1][j-1] - 1)/2)
                         +  max(0, (vec[i-1][j] - 1)/2) ;

            vec[i][i] = max(0, (vec[i-1][i-1] - 1)/2 );     
        }
        if(vec[row][col] >= 1)
            return 1;
        return max(0, vec[row][col]);
    }
};