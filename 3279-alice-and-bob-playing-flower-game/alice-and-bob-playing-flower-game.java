class Solution {
    public long flowerGame(int n, int m) 
    {
        int neven,nodd;
        int meven,modd;
        neven = nodd = n/2;
        meven = modd = m/2;
        if((n&1) == 1)
            nodd++;
        if((m&1) == 1)
            modd++;
        return (long)neven * modd + (long)nodd * meven;
    }
}