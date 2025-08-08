class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) 
    {
        if( target == 1 )
            return false;
        int n = nums.size();
        long long pro = 1, prod = 1;
        return check(nums,n,0,target,pro,prod);
    }
    bool check( vector<int> &nums,int n, int ind, long long target, long long pro, long long prod)
    {
        if(pro == target && prod == target && ind >= n )
            return true;
        if( pro > target || prod > target || ind >= n )
            return false;
        return  check( nums,n,ind+1,target,pro * nums[ind],prod ) || 
                check( nums,n,ind+1,target,pro,prod * nums[ind] );
    }
};