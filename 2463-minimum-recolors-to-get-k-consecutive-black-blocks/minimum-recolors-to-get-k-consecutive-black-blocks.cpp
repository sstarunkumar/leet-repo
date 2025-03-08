class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int l=blocks.size();
        int whites=0,blacks=0;
        for(int i=0;i<k;i++)
        {
            if(blocks[i]=='W')
                whites++;
            else
                blacks++;
        }
        int ans=k;
        ans=min(whites,ans);
        for(int i=k;i<l;i++)
        {
            if(blocks[i]=='W')
                whites++;
            else
                blacks++;
            if(blocks[i-k]=='W')
                whites--;
            else
                blacks--;
            ans=min(ans,whites);
        }
        return ans;
    }
};