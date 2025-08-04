class Solution {
public:
    bool slide(vector<int> &nums,int n,int k)
    {
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++)
            mp[ nums[i] ] ++;
        if( mp.size() <= 2 )
            return true;
        for(int i=k;i<n;i++)
        {
            mp[ nums[i] ]++;
            mp[ nums[i-k] ]--;
            if( mp[ nums[i-k] ] == 0 )
                mp.erase( nums[i-k] );
            if(mp.size() <= 2)
                return true;
        }
        return false;
    }
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size();
        int lo = 0,hi = n;
        int ans = 0;
        while( lo<=hi )
        {
            int mid = lo + (hi-lo)/2;
            bool val = slide(fruits,n,mid);
            cout<<mid<<" "<<val<<endl;
            if( val )
            {
                ans = mid;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        return ans;
    }
};