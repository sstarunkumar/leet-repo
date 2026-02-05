class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
        int n = nums.size(), x;
        vector<int> vec(n);
        for(int i=0;i<n;i++)
        {
            x = ( (nums[i] + i) % n + n ) % n;
            vec[i] = nums[x];
        }
        return vec;
    }
};