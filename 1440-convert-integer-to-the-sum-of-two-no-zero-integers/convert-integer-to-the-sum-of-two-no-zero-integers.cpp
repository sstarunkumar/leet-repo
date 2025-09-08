class Solution {
public:
    bool zero(int n)
    {
        while(n)
        {
            if(n%10 == 0)
                return false;
            n=n/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) 
    {
        for(int i=1;i<=n/2;i++)
            if( zero(i) && zero(n-i) )
                return {i,n-i};
        return {n-1,1};
    }
};