class Solution 
{
public:
    int setbits(int n)
    {
        int c = 0;
        while(n!=0)
        {
            c++;
            n = n & (n-1);
        }
        return c;
    }
    int countPrimeSetBits(int left, int right) 
    {
        vector<int> prime(33,true);
        prime[0] = prime[1] = false;
        for(int i=2;i<33;i++)
            if(prime[i])
                for(int j=i+i;j<33;j+=i)    
                    prime[j] = false;
        int c = 0;
        for(int i=left;i<=right;i++)
            if( prime[ setbits(i) ] )
                c++;
        return c;
    }
};