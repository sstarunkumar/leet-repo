class Solution {
public:
    int bits(int n)
    {
        int ans = 0;
        while(n)
        {
            n = n & (n-1);
            ans++;
        }
        return ans;
    }
    vector<int> sortByBits(vector<int>& arr) 
    {
        sort( begin(arr), end(arr), [&](int a, int b)
        {
            int aa = bits(a);
            int bb = bits(b);
            if(aa == bb)
                return a < b;
            return aa < bb;
        } );
        return arr;
    }
};