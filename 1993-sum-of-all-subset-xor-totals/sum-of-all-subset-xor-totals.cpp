class Solution {
public:
    bool checkbit(int n,int i)
    {
        return (n>>i) & 1 ;
    }
    int subsetXORSum(vector<int>& nums) 
    {
        int n = nums.size(); 
        int x = (1<<n);    
        int ans =0;   
        for(int i=0;i<x;i++)
        {
            int xoro = 0;
            for(int j=0;j<32;j++)
            {
                if(checkbit(i,j))
                    xoro^=nums[j];
            }
            ans +=xoro;
        }
        return ans;
    }
};