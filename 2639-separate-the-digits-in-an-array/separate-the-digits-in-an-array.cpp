class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) 
    {
        vector<int> ans;
        for(int & i : nums)
        {
            int n = floor( log10(i) ), t = pow(10, n);
            for(int j=0;j<=n;j++)
            {
                ans.push_back(i / t);
                i = i % t;
                t = t/10;
            }
        }
        return ans;
    }
};