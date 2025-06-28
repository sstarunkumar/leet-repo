class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<> > pq;
        int n = nums.size();

        for(int i=0;i<k;i++)
            pq.push({nums[i],i});

        for(int i=k;i<n;i++)
        {
            pq.push({nums[i],i});
            pq.pop();
        }    
        vector<pair<int,int>> vec;
        while(!pq.empty())
        {
            vec.push_back(pq.top());
            pq.pop();
        }
        sort(vec.begin(),vec.end(),[](auto &a,auto &b)
        {
            return a.second < b.second;
        });
        vector<int> res;
        for(auto &i : vec)
            res.push_back(i.first);
        return res;
    }
};