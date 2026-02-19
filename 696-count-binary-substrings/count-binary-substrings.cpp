class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        int n = s.size(), prev = 0, i=0, ans = 0;
        char ch = '0';
        while(i<n)
        {
            int curr = 0;
            while(i<n && s[i] == ch)
            {
                curr ++;
                i++;
            }
            ans += min(prev, curr);
            prev = curr;
            ch = (ch == '0') ? '1' : '0';
        }
        return ans;
    }
};