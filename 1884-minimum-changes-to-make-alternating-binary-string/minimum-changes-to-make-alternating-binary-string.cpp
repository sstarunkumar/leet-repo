class Solution {
public:
    int minOperations(string s) 
    {
        int n = s.size();
        int zero = 0, one = 1;
        int x = 0, y = 0;
        int bot;
        for(int i=0;i<n;i++)
        {
            bot = s[i] - '0';
            if(zero != bot)
                x++;
            if(one != bot)
                y++;
            zero ^= 1, one ^= 1;
        }
        return min(x, y);
    }
};