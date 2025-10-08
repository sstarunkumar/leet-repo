class Solution {
public:
    int bsearch(vector<int> &potions,int lo,int hi,int k,long long &success)
    {
        int ans = -1;
        while( lo<=hi )
        {
            int mid = lo + (hi-lo)/2;
            if( 1ll*potions[mid] * k < success )
                ans = mid, lo = mid+1;
            else
                hi = mid-1;
        }
        return ans + 1;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        sort(potions.begin(), potions.end());
        int n = potions.size(), s = spells.size();
        vector<int> ans(s);
        for(int i=0;i<s;i++)
            ans[i] = n - bsearch(potions,0,n-1,spells[i],success);
        return ans;
    }
};