class Solution {
public:
    int furthestDistanceFromOrigin(string moves) 
    {
        int l = 0, r = 0, z = 0;
        for(char & ch : moves)
        {
            if(ch == 'L')
                l++;
            else if( ch == 'R' )
                r++; 
            else
                z++;
        }    
        int p = r - l;
        return max( abs(p + z), abs(p - z) );
    }
};