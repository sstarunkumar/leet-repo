class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        int i=0;
        for(i=30; i >= 0; i--)
        {
            if( (n>>i) & 1 )
                break;
        }
        int x = 0;
        for( ; i >= 0; i--)
        {
            if( ( (n>>i) & 1) == x )
                return false;
            x ^= 1;
        }
        return true;
    }
};