class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(), meetings.end());
        int s = meetings.size();
        vector<int> count(n, 0);

        priority_queue< int, vector<int>, greater<> > rooms;   

        for(int i=0;i<n;i++)
            rooms.push(i);

        priority_queue< pair<long, long> , vector< pair<long, long> > , greater<> > endRoom;
        for(int i=0;i<s;i++)
        {
            int start = meetings[i][0], end = meetings[i][1];
            while( !endRoom.empty() && endRoom.top().first <= start )
            {
                rooms.push( endRoom.top().second );
                endRoom.pop();
            }
            if( rooms.empty() )
            {
                pair<long, long> p = endRoom.top();
                endRoom.pop();

                count[p.second]++;
                endRoom.push({ p.first + end - start , p.second });
            }
            else
            {
                int room = rooms.top();
                rooms.pop();

                count[room]++;
                endRoom.push({ end, room });
            }
        }
        int val = 0, ans = 0;
        for(int i=0;i<n;i++)
        {
            if( count[i] > val )
            {
                val = count[i];
                ans = i;
            }
        }
        return ans;
    }
};