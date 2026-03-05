class Solution {
public:
    int minOperations(string s) 
    {
        int n = s.size();
        int one = 1;
        int x = 0, y = 0;
        for(int i=0;i<n;i++)
        {
            int b = s[i] - '0';
            x += (b != one);
            one ^= 1;
            y += (b != one);
        }
        return min(x, y);
    }
};