class Solution 
{
public:
    int bssearch(vector<int> &vec,int k)
    {
        int lo = 0, hi = vec.size() - 1;
        int ans = -1;
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            if( vec[mid] > k )
            {
                ans = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return ans;
    }
    vector<int> avoidFlood(vector<int>& rains) 
    {
        unordered_map<int,int> mp;
        int n = rains.size();
        vector<int> vec, ans(n,1);
        for(int i=0;i<n;i++)
        {
            if(rains[i] == 0)
                vec.push_back(i);
            else
            {
                ans[i] = -1;
                if(mp.count(rains[i]))
                {
                    int first = mp[rains[i]], bs = bssearch(vec,first);
                    if(bs == -1)
                        return {};
                    ans[ vec[bs] ] = rains[i];
                    vec.erase(vec.begin()+bs);
                }
                mp[ rains[i] ] = i;
            }
        }
        return ans;
    }
};