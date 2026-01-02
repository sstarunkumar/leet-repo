class Solution {
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        unordered_set<int> settu;
        for(int &i:nums)
        {
            if( settu.count(i) )
                return i;
            settu.insert(i);
        }
        return 7;
    }
};