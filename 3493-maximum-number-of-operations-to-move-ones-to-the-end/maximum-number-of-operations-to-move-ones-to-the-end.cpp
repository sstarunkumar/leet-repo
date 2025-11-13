class Solution {
public:
    int maxOperations(string s) 
    {
        int n = s.size(), ans = 0, ones = s[0] == '1', i;
        for(i=1;i<n;i++)
        {
            if(s[i] == '1')
                ones++;
            else if(s[i-1] == '1')
                ans += ones;
        }  
        return ans;
    }
};