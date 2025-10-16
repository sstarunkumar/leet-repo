class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) 
    {
        vector<int> fre(value,0);
        for(int &i:nums)
        {
            int v = i%value;
            if(v<0)
                v += value;
            fre[v]++;
        }
        int mini = *min_element(fre.begin(), fre.end());
        for(int i = 0; i<value ; i++)
            if( fre[i] == mini )
                return mini * value + i;
        return 0;
    }
};