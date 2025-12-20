class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int r = strs.size();
        int c = strs[0].size();
        int ans = 0;
        for(int j=0;j<c;j++)
        {
            for(int i=1;i<r;i++)
            {
                if( strs[i-1][j] > strs[i][j] )
                {
                    ans++;
                    break;
                }
            }
        }    
        return ans;
    }
};