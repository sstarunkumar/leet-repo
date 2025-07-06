class FindSumPairs {
public:
    unordered_map<int,int> mp;
    vector<int> vec1,vec2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        vec1 = nums1;
        vec2 = nums2;
        for(int &i:vec2)
            mp[i]++;
    }
    
    void add(int index, int val) 
    {
        mp[vec2[index]] -- ;
        mp[vec2[index] + val] ++;
        vec2[index] += val;
    }
    
    int count(int tot) 
    {
        int ans = 0;
        for(int &i:vec1)
            ans += mp[ tot - i ];
        return ans;    
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */