class Solution {
public:
    bool checkbit(int n, int i)
    {
        return (n>>i) & 1 ;
    }
    vector<int> minBitwiseArray(vector<int>& nums) 
    {
        for(int & i : nums)
        {
            if(i == 2)
            {
                i = -1;
                continue;
            }
            int j;
            for(j=0;j<31;j++)
            {
                if( !checkbit(i, j) )
                {
                    i = i ^ (1<<(j-1));
                    break;
                }
            }
        }
        return nums;
    }
};