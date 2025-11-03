class Solution {
public:
    int minCost(string colors, vector<int>& need) 
    {
        int sum = 0;
        int n = colors.size();
        for(int i=0;i<n;)
        {
            int j = i+1;
            int c = 1;
            priority_queue< int, vector<int>, greater<> > pq;
            pq.push(need[i]);
            while( j<n && colors[i] == colors[j] )
            {
                pq.push(need[j]);
                j++, c++;
            }
            while(c > 1)
            {
                sum += pq.top();
                pq.pop();
                c--;
            }
            i = j;
        }
        return sum;
    }
};