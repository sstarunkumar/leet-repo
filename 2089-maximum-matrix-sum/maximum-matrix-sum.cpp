class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        long long sum = 0;
        int r = matrix.size();
        int c = 0;
        int mini = INT_MAX;
        for(int i = 0; i<r; i++)
        {
            for(int &j : matrix[i])
            {
                if(j < 0)
                    c++;
                mini = min( mini, abs(j) );
                sum += abs(j);
            }
        }
        if(c&1)
            return sum - 2 * mini;
        return sum;
    }
};