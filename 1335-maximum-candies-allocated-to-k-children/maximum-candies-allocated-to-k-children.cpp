class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) 
    {
        int n = candies.size();
        int lo = 1;
        int hi = *max_element(candies.begin(),candies.end());
        int ans = 0;
        while(lo <= hi)
        {
            int mid=lo+(hi-lo)/2;
            long long q=0;
            for(int i:candies)
                q+=i/mid;
            if(q>=k)
            {
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        return ans;
    }
};