class Solution 
{
public:
    int nsum(int n)
    {
        return n * (n+1) / 2;
    }
    int totalMoney(int n) 
    {
        int q = n/7;
        int r = n%7;
        int ans = q * 28 + (q-1)*q/2 * 7;
        if( r == 0 )
            return ans;
        return ans + nsum(r) + r*q;
    }
};