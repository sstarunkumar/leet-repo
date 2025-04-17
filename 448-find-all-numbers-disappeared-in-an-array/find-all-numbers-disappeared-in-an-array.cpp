class Solution {
public:
    bool bssearch(vector<int> &vec,int k)
    {
        int lo = 0,hi=vec.size()-1;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(vec[mid]==k)
                return true;
            if(vec[mid] < k)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return false;
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        /*
        //solution -1
        int n=nums.size();
        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            bool flag = true;
            for(int j:nums)
                if(j==i)
                {
                    flag=false;
                    break;
                }
            if(flag)
                ans.push_back(i);
        }    
        return ans;
        // solution -2;
        int n=nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=n;i++)
        {
            if(!bssearch(nums,i))
                ans.push_back(i);
        }
        return ans;
        */
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> ans;
        int n=nums.size();
        for(int i=1;i<=n;i++)
            if(!s.count(i))
                ans.push_back(i);
        return ans;
    }
};