class Solution {
public:
    bool canrob(vector<int> &nums,int k,int mid)
    {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] <= mid)
            {
                ans++;
                if(ans>=k)
                    return true;
                i++;
            }
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) 
    {
        auto x = minmax_element(nums.begin(),nums.end());
        int lo = *x.first;
        int hi = *x.second;
        int ans = lo;
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            if(canrob(nums,k,mid))
            {
                ans=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        return ans;  
    }
};