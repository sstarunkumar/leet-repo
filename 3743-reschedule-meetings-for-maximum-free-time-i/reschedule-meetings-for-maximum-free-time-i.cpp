class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) 
    {
        int n = startTime.size();
        vector<int> gaps(n+1);
        gaps[0] = startTime[0] ;
        for(int i=1;i<n;i++)
            gaps[i] = startTime[i] - endTime[i-1] ;
        gaps[n] = eventTime - endTime[n-1] ;
        n++,k++;
        int ans = 0,sum = 0;
        for(int i=0;i<k;i++)
            sum += gaps[i];
        ans = max(ans , sum);
        for(int i=k;i<n;i++)
        {
            sum += gaps[i];
            sum -= gaps[i-k];
            ans = max(ans , sum);
        }
        return ans;
    }
};