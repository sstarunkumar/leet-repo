class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) 
    {
        int n = diff.size();
        long sum=0;
        long mini = 0,maxi = 0;
        for(int i=0;i<n;i++)
        {
            sum+=diff[i];
            mini = min(mini,sum);
            maxi = max(maxi,sum);
        }
        int difference = maxi-mini;
        int ans= upper - lower - difference + 1;
        return ans>0 ? ans:0;
    }
};