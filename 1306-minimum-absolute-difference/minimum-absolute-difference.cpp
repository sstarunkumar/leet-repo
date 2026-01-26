class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) 
    {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int mini = INT_MAX;
        vector< vector<int> > vec;
        for(int i=1;i<n;i++)
        {
            int d = nums[i] - nums[i-1];
            if(d < mini)
            {
                vec.clear();
                vec.push_back( {nums[i-1], nums[i] } );
                mini = d;
            }
            else if(d == mini)
                vec.push_back( {nums[i-1], nums[i] } );
        }    
        return vec;
    }
};