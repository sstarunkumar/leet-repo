class Solution 
{
    static char arr[][] = new char[9][9];
    public void solveSudoku(char[][] board) 
    {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                arr[i][j] = board[i][j];
        solve(0,0);
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                board[i][j] = arr[i][j];
    }
    public static boolean valid(int r,int c, char ch)
    {
        for(int i=0;i<9;i++)
            if(arr[r][i] == ch || arr[i][c] == ch)
                return false;
        r = (r/3) * 3;
        c = (c/3) * 3;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                if(arr[i+r][j+c] == ch)
                    return false;
        }
        return true;
    }
    public static boolean solve(int r,int c)
    {
        if(r == 9)
            return true;
        if(c == 9)
            return solve(r+1,0);
        if(arr[r][c] != '.')
            return solve(r,c+1);
        for(int i=1;i<=9;i++)
        {
            if( valid( r,c,(char)('0'+i) ) )
            {
                arr[r][c] = (char)('0'+i) ;
                if( solve(r,c+1) )
                    return true;
                arr[r][c] = '.';
            }
        }
        return false;
    }
}