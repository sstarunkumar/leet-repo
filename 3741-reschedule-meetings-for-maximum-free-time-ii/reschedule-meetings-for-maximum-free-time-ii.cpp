class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) 
    {
        int n = startTime.size();
        vector<int> gaps(n+1);
        gaps[0] = startTime[0];
        for(int i=1;i<n;i++)
            gaps[i] = startTime[i] - endTime[i-1];
        gaps[n] = eventTime - endTime[n-1];

        vector<int> l(n,0),r(n,0);

        int sum = 0;
        for(int i=1;i<n;i++)
        {
            sum = max(sum,gaps[i-1]);
            l[i] = sum;
        }
        sum = 0;
        for(int i=n-2;i>=0;i--)
        {
            sum = max(sum,gaps[i+2]);
            r[i] = sum;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int durn = endTime[i] - startTime[i];
            int space = gaps[i] + gaps[i+1];
            if(durn <= l[i] || durn <= r[i])
                ans = max(ans , durn + space);
            else
                ans = max(ans , space);
        }
        return ans;
    }
};