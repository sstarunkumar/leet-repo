class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        int n = nums.size();
        set<int> shetty;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == key)
            {
                int j = i - k >= 0 ? i-k : 0 ;
                for(  ; abs(i-j) <= k && j<n ;j++)
                    shetty.insert(j);
            }
        }
        vector<int> vec(shetty.begin(),shetty.end());
        return vec;
    }
};