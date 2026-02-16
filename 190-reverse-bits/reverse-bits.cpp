class Solution {
public:
    int reverseBits(int n) 
    {
        int x = 0;
        for(int i=0;i<31;i++)
            if( (n >> i) & 1 )
                x |= 1 << (31 - i) ;
        return x;
    }
};