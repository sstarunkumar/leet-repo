class Solution {
public:
    int minOperations(string s) 
    {
        int n = s.size();
        int oddones = 0, evenones = 0;
        int even = (n+1)/2, odd = n/2;

        for(int i=0; i < n; i += 2 )
            if(s[i] == '1')     evenones++;
        for(int i = 1; i < n; i += 2)
            if(s[i] == '1')     oddones++;
        
        // ideal places have, 
        // even = 1    odd = 0
        // evenzeroes      + oddones
        // even - evenones + oddones

        // even = 0    odd = 1
        // evenones + oddzeroes
        // evenones + odd - oddones
        return min( even - evenones + oddones, evenones + odd - oddones );
    }
};