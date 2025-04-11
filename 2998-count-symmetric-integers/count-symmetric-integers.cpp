class Solution {
public:
    int n;
    bool check(string s)
    {
        n = s.size();
        if(n&1)
            return false;
        int sum1=0,sum2=0;
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            sum1+=s[i];
            sum2+=s[j];
        }
        return sum1==sum2;
    }    
    int countSymmetricIntegers(int low, int high) 
    {
        int ans =0;
        for(int i=low ;i<= high;i++)
            if(check(to_string(i)))
                ans++;
        return ans;
    }
};