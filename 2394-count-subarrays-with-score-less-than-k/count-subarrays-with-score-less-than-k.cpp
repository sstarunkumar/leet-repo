class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        int n= nums.size(),left = 0;
        long long length = 0,score = 0,sum = 0,ans = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            length++;
            score = sum * length;
            while(score >= k && left<i)
            {
                length--;
                sum-=nums[left];
                left++;
                score = sum * length;
            }
            if(score < k)
                ans += length;
        }
        return ans;
    }
};