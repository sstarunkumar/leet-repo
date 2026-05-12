class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) 
    {
        int ans = 0;
        sort(tasks.begin(), tasks.end(), [&](vector<int> &a, vector<int> &b)
        {       return a[1] - a[0] < b[1] - b[0];           });
        for(auto i : tasks)
            ans = max(i[1], ans + i[0]);
        return ans;
    }
};