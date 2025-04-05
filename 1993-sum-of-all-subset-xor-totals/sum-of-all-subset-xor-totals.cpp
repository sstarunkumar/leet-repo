class Solution {
public:
    int sum =0;
    void xorsum(vector<int> &nums,int n,int xoro,int ind)
    {
        if(ind>=n)
        {
            sum+=xoro;
            return;
        }
        xorsum(nums,n,xoro^nums[ind],ind+1);
        xorsum(nums,n,xoro,ind+1);
    }
    int subsetXORSum(vector<int>& nums) 
    {
        int n = nums.size();
        xorsum(nums,n,0,0);
        return sum;
    }
};