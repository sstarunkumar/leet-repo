class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        priority_queue<int> maxh;
        priority_queue<int,vector<int>,greater<int>> minh;
        int n = weights.size();
        int x;
        for(int i=1;i<k;i++)
        {
            x = weights[i] + weights[i-1];
            minh.push(x);
            maxh.push(x);
        }
        for(int i=k;i<n;i++)
        {
            x = weights[i]+weights[i-1];            
            minh.push(x);
            maxh.push(x);
        }

        long long mini =0;
        for(int i=1;i<k;i++)
        {
            mini += minh.top();
            minh.pop();
        }
        long long maxi = 0;
        for(int i=1;i<k;i++)
        {
            maxi += maxh.top();
            maxh.pop();
        }
        return maxi - mini;
    }
};