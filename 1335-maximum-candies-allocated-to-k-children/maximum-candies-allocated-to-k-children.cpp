class Solution {
public:
    bool isgivable(vector<int> &candies,long long k,int mid)
    {
        int n=candies.size();
        long long q=0;
        for(int i=0;i<n;i++)
        {
            q+=candies[i]/mid;
            if(q>=k)
                return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) 
    {
        int n = candies.size();
        int lo = 1,ans=0;
        int hi = 1e7;
        while(lo <= hi)
        {
            int mid=lo+(hi-lo)/2;
            if(isgivable(candies,k,mid))
            {
                ans=mid;
                lo = mid+1;
            }
            else
                hi=mid-1;
        }
        return ans;
    }
};