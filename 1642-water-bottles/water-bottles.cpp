class Solution {
public:
    int numWaterBottles(int n, int k) 
    {
        int ans = n;
        int b = n/k;
        while(b)
        {
            ans += b;
            n = b + n%k;
            b = n/k;
        }
        return ans;
    }
};