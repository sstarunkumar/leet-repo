class Solution {
public:
    string s = "a";
    void compute()
    {
        if(s.size() > 500)
            return ;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            int val = s[i] - 'a' + 1;
            if(val == 26)
                val = 0;
            s += 'a'+val;
        }
        compute();
    }
    char kthCharacter(int k) 
    {
        compute();
        return s[k-1];
    }
};