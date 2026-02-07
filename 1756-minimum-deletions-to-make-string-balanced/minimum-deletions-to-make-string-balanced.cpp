class Solution {
public:
    int minimumDeletions(string s) 
    {
        int l = s.size();
        int a = 0, c = 0;
        for(int i=l-1; i >= 0; i--)
        {
            if(s[i] == 'a')
                a++;
            else if(a)
            {
                a--;
                c++;
            }            
        }    
        return c;
    }
};