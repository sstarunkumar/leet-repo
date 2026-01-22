class Solution {
public:
    bool sorted(vector<int> &nums)
    {
        int n = nums.size();
        for(int i=1;i<n;i++)
            if( nums[i-1] > nums[i] )
                return false;
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) 
    {
        int c = 0, n = nums.size();
        int ind, mini, sum;
        while( ! sorted(nums) )
        {
            c++;
            mini = INT_MAX;
            for(int i=1;i<n;i++)
            {
                sum = nums[i-1] + nums[i];
                if(sum < mini)
                {
                    ind = i;
                    mini = sum;
                }
            }
            nums[ind-1] = mini;
            nums.erase(nums.begin() + ind);
            n--;
        }   
        return c;
    }
};