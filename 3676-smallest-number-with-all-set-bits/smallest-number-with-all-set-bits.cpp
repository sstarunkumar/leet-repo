class Solution {
public:
    bool checkbit(int n,int i)
    {
        return (n>>i) & 1 ;
    }
    int smallestNumber(int n) 
    {
        bool flag = false;
        for(int i=9;i>=0;i--)
        {
            if( checkbit(n, i) )
                flag = true;
            if(flag)
                n = n | (1<<i);
        }
        return n;
        // 1
        // 3
        // 7 
        // 15 
        // 31
        // 63
        // 127
        // 255
        // 511
        // 1023
    }
};