class Solution {
public:
    int mod = 1e9+7;
    int numberOfWays(string corridor) 
    {
        int s = 0;
        for(char &ch : corridor)
            if(ch == 'S')
                s++;
        if(s&1 || s == 0)
            return 0;
        long long ans = 1;
        //3 5 6 
        s = 0;
        int c = 1;
        for(char &ch : corridor)
        {
            if(ch == 'S')
            {
                s++;
                if(s&1 && s>1)
                    ans = (ans * c)%mod;
                c = 1;
            }
            else
                c++;
        }
        return ans%mod;
    }
};