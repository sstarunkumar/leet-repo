class Solution {
public:
    #started iterating from the top right corner of the grid [0][m-1] since big values are placed down and smaller values placed left
    # iteraing from top left is ambiguous since both(right and down) has bigger values.
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int r=0,c=matrix[0].size()-1;
        while(r<matrix.size() && c>=0)
        {
            if(matrix[r][c] < target)
                r++;
            else if(matrix[r][c] > target)  
                c--;
            else
                return true;
        }
        return false;
    }
};
