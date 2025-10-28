class Solution {
public:
    int countValidSelections(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> left(n), right(n);
        left[0] = nums[0];
        for(int i=1;i<n;i++)
            left[i] = left[i-1] + nums[i];    
        right[n-1] = nums[n-1];
        for(int i = n-2; i>=0 ;i--)
            right[i] = nums[i] + right[i+1];
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                int d = abs( left[i] - right[i] );
                if(d == 0)
                    sum += 2;
                else if(d == 1)
                    sum += 1;
            }
        }
        return sum;        
    }
};