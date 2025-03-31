class Solution {
public:
    void print(vector<int> &vec)
    {
        for(auto i:vec)
            cout<<i<<" ";
        
    }
    long long putMarbles(vector<int>& weights, int k) 
    {
        if(k == 1)
            return 0;
        priority_queue<int> maxh;
        int n = weights.size();
        for(int i=1;i<n;i++)
        {
            maxh.push( weights[i] + weights[i-1] );
        }
        long long mini = 0,maxi = 0;
        k--;
        int i=0;
        vector<int> ans(k);
        while(i<k)
        {
            mini += ans[i] = maxh.top(); 
            maxh.pop();
            i++;
        }
        for(int i=k;!maxh.empty();i++,maxh.pop())
        {
            ans[i%k] = maxh.top();
        }
        for(auto i:ans)
            maxi+=i;
        return mini - maxi;
    }
};