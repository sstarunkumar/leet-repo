class Solution {
public:
    vector<int> sumZero(int n) 
    {
        vector<int> a(n,0);
        for(int i=0;i<n/2;i++)
            a[i] = i+1;
        int i=0, j=n-1;
        while(i<j)
        {
            a[j] = -a[i];
            i++,j--;
        }
        return a;
    }
};