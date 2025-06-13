class Solution {
public:
    bool valid(vector<int> &nums,int k,int p)
    {
        int counter = 0;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i] - nums[i-1] <= k)
            {
                i++;
                counter++;
                if(counter >= p)
                    return true;
            }
        }
        return counter >= p ;
    }
    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin(),nums.end());
        int lo = 0,hi = nums.back() - nums[0];
        int ans = 0;
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            if( valid(nums,mid,p) )
            {
                ans = mid;
                hi=mid-1;
            }
            else
                lo = mid+1;
        }
        return ans;
    }
};

//  0  3  4  5