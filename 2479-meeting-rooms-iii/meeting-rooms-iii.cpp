class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(),meetings.end());
        priority_queue<int,vector<int>,greater<>> rooms;
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<>> heap;
        for(int i=0;i<n;i++)
            rooms.push(i);
        int x = meetings.size();
        vector<int> fre(n);
        for(int i=0;i<x;i++)
        {
            long s = meetings[i][0];
            long e = meetings[i][1];
            while(!heap.empty() && heap.top().first <= s)
            {
                rooms.push(heap.top().second);
                heap.pop();
            }
            int t;
            if(rooms.empty())
            {
                long d = e - s;
                s = heap.top().first;
                e = s + d;
                t = heap.top().second;
                heap.pop();              
            }
            else
            {
                t = rooms.top();
                rooms.pop();
            }
            fre[t]++;
            heap.push({e,t});
        }
        int ans = 0,sum = 0;
        for(int i=0;i<n;i++)
            if(fre[i] > sum)
            {
                sum = fre[i];
                ans = i;
            }    
        return ans;
    }
};