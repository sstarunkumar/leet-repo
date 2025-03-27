class Solution {
public:
    int minimumIndex(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        int n = nums.size();
        int val,fre;
        val=0,fre=0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]] ++;
            int mpfre = mp[nums[i]];
            if(mpfre > fre)
            {
                val = nums[i];
                fre = mpfre;
            }
        }
        fre = 0;
        vector<int> vec(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i] == val)
                fre++;
            vec[i]=fre;
        }
        for(int i=0;i<n-1;i++)
        {
            //    2           1           3       2           (4-1)/2
            if( vec[i] > (i+1)/2 && vec[n-1] - vec[i] > (n-i-1)/2 )
                return i;
        }
        return -1;
    }
};