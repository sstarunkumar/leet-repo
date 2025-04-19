class Solution {
public:
    int bsfloor(vector<int> &vec,int index,int k)
    {
        int n = vec.size();
        int lo = index,hi = n-1;
        int ans=-1;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(vec[mid] <= k)
            {
                ans = mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            int x=bsfloor(nums,i,upper-nums[i]);
            cout<<x<<" ";
            ans += x==-1 ? 0 : x - i;
            x = bsfloor(nums,i,lower-nums[i]-1);
            cout<<x<<endl;
            ans -= x==-1 ? 0 :x-i;
        }
        
        return ans;
    }
};
// 0 1 4 4 5 7