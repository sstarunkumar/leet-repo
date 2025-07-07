class Solution {
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(),events.end());
        int d = 0;
        int ans = 0;
        int n = events.size();
        for(int i=0;i<n;i++)
            d = max(d,events[i][1]);
        int j=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<=d;i++)
        {
            while(j<n && events[j][0] <= i)
            {
                pq.push(events[j][1]);
                j++;
            }
            while(!pq.empty() && pq.top() < i)
            {
                pq.pop();
            }
            if(!pq.empty())
            {
                ans ++;
                pq.pop();
            }
        }
        return ans ;
    }
};