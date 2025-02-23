class Solution {
public:
    bool check(vector<vector<char>> &board,int r,int c)
    {
        for(int i=0;i<board.size();i++)
        {
            if(board[i][c] == board[r][c] && r!=i)      
                return false;
            if(board[r][i] == board[r][c] && i!=c)
                return false;
        }
        int p = (r/3)*3;
        int q = (c/3)*3;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if( board[p+i][q+j] == board[r][c] && (r!=p+i || c!=q+j) )
                    return false;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]!='.')
                {
                    if(!check(board,i,j))
                        return false;
                }
            }
        }
        return true;
    }
};