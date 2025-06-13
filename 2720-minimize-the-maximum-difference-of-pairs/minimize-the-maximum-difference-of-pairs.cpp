class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) 
    {
        if(p == 0)  return false;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int lo = 0,hi = nums.back() - nums[0];
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2 , counter = 0;
            for(int i=1;i<n;i++)
            {
                if(nums[i] - nums[i-1] <= mid)
                {
                    counter++;
                    i++;
                }
            }
            if( counter >= p )      hi=mid-1;
            else                    lo = mid+1;
        }
        return hi+1;
    }
};

//  0  3  4  5