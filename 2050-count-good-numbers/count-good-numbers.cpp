class Solution {
public:
    int mod = 1e9+7;
    long long power(int n,long long k)
    {
        if(k==0)
            return 1;
        long long x = power(n,k/2);
        if(k&1)
            return ((x*x)%mod *n) % mod;
        return (x*x)%mod;
    }
    int countGoodNumbers(long long n) 
    {
        long long fives = (n+1)/2;
        long long fours = n/2;
        return ( power(5,fives) * power(4,fours) ) % mod;
    }
};
    /*
    ----
    eoeo
    5454
    */