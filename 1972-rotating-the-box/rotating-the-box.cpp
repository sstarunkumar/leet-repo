class Solution {
public:
    void move(vector<char> &vec, int c)
    {
        int spaces = 0;
        for(int i = c - 1 ; i >= 0 ; i-- )
        {
            if( vec[i] == '.' )
                spaces++;
            else if(vec[i] == '*' )
                spaces = 0;
            else
            {
                vec[i] = '.';
                vec[i+spaces] = '#';
            }
        }
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
    {
        int r = box.size(), c = box[0].size();

        for(vector<char> & vec : box)
            move(vec, c);
        vector< vector<char> > ans(c, vector<char> (r));
        
        for( int i=0 ; i < r ; i++ )
        {
            for( int j = 0 ; j < c ; j++ )
                ans[j][r - i - 1] = box[i][j];
        }
        return ans;
    }
};