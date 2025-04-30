class Solution {
public:
    int findNumbers(vector<int>& nums) 
    {
        int count = 0;
        for(int &i:nums)
            if(!(to_string(i).size()&1))
                count++;
        return count;
    }
};