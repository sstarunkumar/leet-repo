class Solution {
public:
    int reverse(int x) 
    {
        int ans=0;
        while(x!=0)
        {
            int r=x%10;
            if(ans > INT_MAX/10)
                return 0;
            if(ans < INT_MIN/10)
                return 0;
            ans=ans*10+r;
            x=x/10;
        }
        return ans;
    }
};