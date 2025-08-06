class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();    
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap( matrix[i][j] , matrix[j][i] );
            }
        }
        for(int i=0;i<n;i++)
        {
            int a = 0,b = n-1,temp;
            while(a<b)
            {
                temp = matrix[i][a],matrix[i][a]=matrix[i][b],matrix[i][b]=temp;
                a++,b--;
            }
        }
    }
};